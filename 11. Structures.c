/*
TASK 1. Championship. Statistics on opponents
*/

#include <stdio.h>
#include <string.h>

#define NAME_LEN 20
#define MAX_TEAMS 10

typedef struct {
    char * name; int games; int away; int wins; int goals;
} Opponent;

typedef struct {
    char name[NAME_LEN + 1];
    int numberOfOpponents;
    Opponent opponents[MAX_TEAMS];
}Team;

int main() {
    FILE *input = fopen("input.txt", "r");
    FILE *output = fopen("output.txt", "w");
    char firstTeamName[NAME_LEN + 1], secondTeamName[NAME_LEN + 1];
    int firstTeamScore, secondTeamScore, teamsCount = 0;
    Team teams[MAX_TEAMS];

    for (; fscanf(input, "%s - %s %d:%d", firstTeamName, secondTeamName, &firstTeamScore, &secondTeamScore) != EOF;) {
        int i, j;
        for (i = 0; i < teamsCount; ++i)
            if (strcmp(firstTeamName, teams[i].name) == 0)
                break;
        if (i == teamsCount) {
            strcpy(teams[teamsCount++].name, firstTeamName);
            teams[teamsCount - 1].numberOfOpponents = 0;
        }
        for (j = 0; j < teamsCount; ++j)
            if (strcmp(secondTeamName, teams[j].name) == 0)
                break;
        if (j == teamsCount) {
            strcpy(teams[teamsCount++].name, secondTeamName);
            teams[teamsCount - 1].numberOfOpponents = 0;
        }

        int k, l;
        for (k = 0; k < teams[i].numberOfOpponents; ++k){
            if (strcmp(teams[j].name, teams[i].opponents[k].name) == 0)
                break;
        }
        if (k == teams[i].numberOfOpponents) {
            teams[i].opponents[teams[i].numberOfOpponents++].name = teams[j].name;
            Opponent *o = teams[i].opponents + teams[i].numberOfOpponents - 1;
            o->games = o->away = o->wins = o->goals = 0;
        }
        for (l = 0; l < teams[j].numberOfOpponents; ++l){
            if (strcmp(teams[i].name, teams[j].opponents[l].name) == 0)
                break;
        }
        if (l == teams[j].numberOfOpponents) {
            teams[j].opponents[teams[j].numberOfOpponents++].name = teams[i].name;
            Opponent *o = teams[j].opponents + teams[j].numberOfOpponents - 1;
            o->games = o->away = o->wins = o->goals = 0;
        }

        Opponent *firstTeamOpponent = teams[i].opponents + k, *secondTeamOpponent = teams[j].opponents + l;
        ++firstTeamOpponent->games;
        firstTeamOpponent->away += 0;
        firstTeamOpponent->wins += firstTeamScore > secondTeamScore;
        firstTeamOpponent->goals += firstTeamScore;

        ++secondTeamOpponent->games;
        secondTeamOpponent->away += 1;
        secondTeamOpponent->wins += secondTeamScore > firstTeamScore;
        secondTeamOpponent->goals += secondTeamScore;

    }

    for (int i = 0; i < teamsCount; ++i) {
        fprintf(output, "%s\n", teams[i].name);
        for (int j = 0; j < teams[i].numberOfOpponents; ++j) {
            Opponent *o = teams[i].opponents + j;
            fprintf(output, "%s %d %d %d %d\n", o->name, o->games, o->away, o->wins, o->goals);
        }
    }
}
