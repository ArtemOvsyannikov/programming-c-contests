/*
TASK 1. Bus fleet
*/

#include <stdio.h>
#include <string.h>
#include <malloc.h>

char commandsStr[][6] = {"ADD", "PRINT", "FIND", "BUS", "STOP", "ALL"};
enum commands {add, print, find, bus, stop, all};

typedef struct {
    char name[51];
    char * buses[10];
    int busCount;
} Stop;
typedef struct {
    char number[6];
    char * stops[30];
    int stopCount;
} Bus;

Stop stops[30 * 10] = {};
Bus buses[10] = {};
int busCount = 0, stopCount = 0;
FILE *input, *output;

int main() {
    input = fopen("input.txt", "r"), output = fopen("output.txt", "w");
    char arg1[6] = "", arg2[51] = "", arg3[51] = "", arg4[51] = "";
    char commandStr[200];
    Bus *curBus; Stop *curStop;

    while (fgets(commandStr, 200, input) != NULL) {
        sscanf(commandStr, "%s %s %s %s", arg1, arg2, arg3, arg4);
        int command = -1;
        for (int i = 0; i < 6; ++i)
            if (strcmp(commandsStr[i], arg1) == 0) { command = i; break; }
        switch (command) {
            case add: {
                int subCommand = -1;
                for (int i = 0; i < 6; ++i)
                    if (strcmp(commandsStr[i], arg2) == 0) { subCommand = i; break; }
                switch (subCommand) {
                    case bus: {
                        if (*arg4 || !*arg3) { fprintf(output, "WRONG %s FORMAT\n", commandsStr[add]); break; }
                        curBus = NULL;
                        for (int i = 0; i < busCount; ++i)
                            if(strcmp(buses[i].number, arg3) == 0) { curBus = &buses[i]; break; }
                        if (!curBus) {
                            if (busCount == 10) fprintf(output, "CAN'T ADD BUS %s. BUSPARK IS FULL\n", arg3);
                            else strcpy(buses[busCount++].number, arg3);
                        } else fprintf(output, "BUS %s ALREADY EXISTS\n", arg3);
                    } break;
                    case stop: {
                        if (!*arg4 || !*arg3) { fprintf(output, "WRONG %s FORMAT\n", commandsStr[add]); break; }
                        curBus = NULL;
                        for (int i = 0; i < busCount; ++i)
                            if(strcmp(buses[i].number, arg3) == 0) { curBus = &buses[i]; break; }
                        curStop = NULL;
                        for (int i = 0; i < stopCount; ++i)
                            if(strcmp(stops[i].name, arg4) == 0) { curStop = &stops[i]; break; }
                        if (!curStop) {
                            strcpy(stops[stopCount].name, arg4);
                            curStop = &stops[stopCount++];
                        }
                        if (curBus){
                            int foundStopInBus = 0;
                            for (int i = 0; i < curBus->stopCount; ++i)
                                if (strcmp(curBus->stops[i], arg4) == 0) { foundStopInBus = 1; break; }
                            if (!foundStopInBus){
                                if (curBus->stopCount == 30)
                                    fprintf(output, "CAN'T ADD STOP %s TO BUS %s. BUS IS FULL\n", arg4, arg3);
                                else {
                                    curBus->stops[curBus->stopCount++] = curStop->name;
                                    curStop->buses[curStop->busCount++] = curBus->number;
                                }
                            } else fprintf(output, "BUS %s ALREADY HAS STOP %s\n", arg3, arg4);
                        } else fprintf(output, "BUS %s DOESN'T EXIST\n", arg3);
                    } break;
                    default: fprintf(output, "WRONG %s FORMAT\n", commandsStr[add]);
                }
            } break;

            case print: {
                int subCommand = -1;
                for (int i = 0; i < 6; ++i)
                    if (strcmp(commandsStr[i], arg2) == 0) { subCommand = i; break; }
                switch (subCommand) {
                    case bus: {
                        if (*arg4 || !*arg3) { fprintf(output, "WRONG %s FORMAT\n", commandsStr[print]); break; }
                        curBus = NULL;
                        for (int i = 0; i < busCount; ++i)
                            if(strcmp(buses[i].number, arg3) == 0) { curBus = &buses[i]; break; }
                        if (!curBus) fprintf(output, "BUS %s DOESN'T EXIST\n", arg3);
                        else {
                            fprintf(output, "%s\nSTOPS: ", curBus->number);
                            for (int i = 0; i < curBus->stopCount; ++i)
                                fprintf(output, "%s ", curBus->stops[i]);
                            fprintf(output, "\n");
                        }
                    } break;
                    case stop: {
                        if (*arg4 || !*arg3) { fprintf(output, "WRONG %s FORMAT\n", commandsStr[print]); break; }
                        curStop = NULL;
                        for (int i = 0; i < stopCount; ++i)
                            if(strcmp(stops[i].name, arg3) == 0) { curStop = &stops[i]; break; }
                        fprintf(output, "%s: ", arg3);
                        if (!curStop || !curStop->busCount) fprintf(output, "NO BUSES GO TO STOP");
                        else for (int i = 0; i < curStop->busCount; ++i)
                                fprintf(output, "%s ", curStop->buses[i]);
                        fprintf(output, "\n");
                    } break;
                    case all: {
                        for (int i = 0; i < busCount; ++i) {
                            curBus = &buses[i];
                            fprintf(output, "%s\nSTOPS: ", curBus->number);
                            for (int j = 0; j < curBus->stopCount; ++j)
                                fprintf(output, "%s ", curBus->stops[j]);
                            fprintf(output, "\n");
                        }
                    } break;
                    default: fprintf(output, "WRONG %s FORMAT\n", commandsStr[print]);
                }
            } break;

            case find: {
                if (!*arg2 || !*arg3 || *arg4) { fprintf(output, "WRONG %s FORMAT\n", commandsStr[find]); break; }
                if (strcmp(arg2, arg3) == 0) { fprintf(output, "STOPS %s ARE THE SAME\n", arg2); break; }
                int foundCount = 0;
                char ** res = malloc(10 * sizeof(char *));
                for (int i = 0; i < busCount; ++i){
                    int foundStop1InBus = 0;
                    for (int j = 0; j < buses[i].stopCount; ++j)
                        if (strcmp(buses[i].stops[j], arg2) == 0) { foundStop1InBus = 1; break; }
                    int foundStop2InBus = 0;
                    for (int j = 0; j < buses[i].stopCount && foundStop1InBus; ++j)
                        if (strcmp(buses[i].stops[j], arg3) == 0) { foundStop2InBus = 1; break; }
                    if (foundStop1InBus && foundStop2InBus)
                        res[foundCount++] = buses[i].number;
                }
                if (foundCount) {
                    fprintf(output, "BUSES FROM %s TO %s:\n", arg2, arg3);
                    for (char **b = res; b - res < foundCount; ++b)
                        fprintf(output, "%s\n", *b);
                } else {
                    typedef struct { char *b1, *b2; } TransferPath;
                    TransferPath * tp = malloc(90 * sizeof(TransferPath)); foundCount = 0;
                    Stop *stop1 = NULL;
                    for (int i = 0; i < stopCount && !stop1; ++i)
                        if(strcmp(stops[i].name, arg2) == 0) stop1 = &stops[i];
                    Stop *stop2 = NULL;
                    for (int i = 0; i < stopCount && !stop2 && stop1 != NULL ; ++i)
                        if(strcmp(stops[i].name,arg3)==0) stop2=&stops[i];
                    Bus *bus1,*bus2;
                    if(stop1!=NULL&&stop2!=NULL){
                      for(int i=0;i<stop1->busCount;++i){
    bus1=NULL;
    for(int j=0;j<busCount;++j){
        if(strcmp(buses[j].number,stop1->buses[i])==0){bus1=&buses[j];break;}
    }
    for(int j=0;j<stop2->busCount;++j){
        bus2=NULL;
        for(int k=0;k<busCount;++k){
            if(strcmp(buses[k].number,stop2->buses[j])==0){bus2=&buses[k];break;}
        }
        int hasCommonStop = 0;
        for (int i = 0; i < bus1->stopCount && !hasCommonStop; ++i)
            for (int j = 0; j < bus2->stopCount; ++j)
                if (strcmp(bus1->stops[i], bus2->stops[j]) == 0) { hasCommonStop = 1; break; }
        if(hasCommonStop)
            tp[foundCount++] = bus1 < bus2 ? (TransferPath) {bus1->number, bus2->number } :
                                             (TransferPath) {bus2->number, bus1->number };
    }
}
                    }
                    if (foundCount) {
                        fprintf(output, "BUSES FROM %s TO %s:\n", arg2, arg3);
                        for (TransferPath *b = tp; b - tp < foundCount; ++b)
                            fprintf(output, "%s %s\n", b->b1, b->b2);
                    } else fprintf(output, "THERE ARE NO BUSES FROM %s TO %s\n", arg2, arg3);
                    free(tp);
                } free(res);
            } break;
            default: fprintf(output, "ERROR\n");
        }
        *arg1 = *arg2 = *arg3 = *arg4 = '\0';
    }
}
