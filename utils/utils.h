#ifndef PORT_SIMULATOR_UTILS_H
#define PORT_SIMULATOR_UTILS_H
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdarg.h>

/**
 * Gera número aleatório no dado intervalo
 * @param min: menor número que pode ser gerado
 * @param max: maior número que pode ser gerado
 * @return número gerado
 */
int gen_number(int min, int max);

/**
 * Verifica se todos os ponteiros são nulos
 * @param n: numero de ponteiros a serem passados no argumento
 * @param ...: ponteiros a serem analisados
 * @return resultado da verificação
 */
bool empty(int n, ...);

/**
 * Calcula média dado numerador e divisor da operação
 * @param numerator: numerador da operação
 * @param denominator: denominador da operação
 * @return média obtida
 */
float average_calculator(float numerator, float denominator);

/**
 * Exibe a unidade de tempo atual e a incrementa
 * @param time_uni: ponteiro para a unidade de tempo
 */
void get_time_uni(int *time_uni);

#endif //PORT_SIMULATOR_UTILS_H
