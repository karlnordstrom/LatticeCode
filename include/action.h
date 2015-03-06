#ifndef ACTION_H
#define ACTION_H

typedef double (*actionPtr)(const unsigned int, const double*, const unsigned int, const double, const double*);
typedef double (*operatorPtr)(const double*, const unsigned int, const unsigned int, const double*);

typedef struct Action {
  actionPtr action;
  const double *parameters;
} Action;

typedef struct Operator {
  operatorPtr op;
  const double *parameters;
} Operator;

#endif
