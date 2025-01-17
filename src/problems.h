/*
 * Copyright (c) 2007-2009, Novell Inc.
 *
 * This program is licensed under the BSD license, read LICENSE.BSD
 * for further information
 */

/*
 * problems.h
 *
 */

#ifndef LIBSOLV_PROBLEMS_H
#define LIBSOLV_PROBLEMS_H

#include "rules.h"

#ifdef __cplusplus
extern "C" {
#endif


struct s_Solver;

#define SOLVER_SOLUTION_JOB		(0)
#define SOLVER_SOLUTION_DISTUPGRADE	(-1)
#define SOLVER_SOLUTION_INFARCH		(-2)
#define SOLVER_SOLUTION_BEST		(-3)
#define SOLVER_SOLUTION_POOLJOB		(-4)
#define SOLVER_SOLUTION_BLACK		(-5)
#define SOLVER_SOLUTION_STRICTREPOPRIORITY	(-6)

void solver_recordproblem(struct s_Solver *solv, Id rid);
void solver_fixproblem(struct s_Solver *solv, Id rid);
Id solver_autouninstall(struct s_Solver *solv, int start);
void solver_disableproblemset(struct s_Solver *solv, int start);

int solver_prepare_solutions(struct s_Solver *solv);

unsigned int solver_problem_count(struct s_Solver *solv);
Id solver_next_problem(struct s_Solver *solv, Id problem);
unsigned int solver_solution_count(struct s_Solver *solv, Id problem);
Id solver_next_solution(struct s_Solver *solv, Id problem, Id solution);
unsigned int solver_solutionelement_count(struct s_Solver *solv, Id problem, Id solution);
Id solver_solutionelement_internalid(struct s_Solver *solv, Id problem, Id solution);
Id solver_solutionelement_extrajobflags(struct s_Solver *solv, Id problem, Id solution);
Id solver_next_solutionelement(struct s_Solver *solv, Id problem, Id solution, Id element, Id *p, Id *rp);

void solver_take_solutionelement(struct s_Solver *solv, Id p, Id rp, Id extrajobflags, Queue *job);
void solver_take_solution(struct s_Solver *solv, Id problem, Id solution, Queue *job);

Id solver_findproblemrule(struct s_Solver *solv, Id problem);
void solver_findallproblemrules(struct s_Solver *solv, Id problem, Queue *rules);
void solver_get_proof(struct s_Solver *solv, Id id, int islearnt, Queue *q);
void solver_get_learnt(struct s_Solver *solv, Id id, int islearnt, Queue *q);

extern const char *solver_problemruleinfo2str(struct s_Solver *solv, SolverRuleinfo type, Id source, Id target, Id dep);
extern const char *solver_problem2str(struct s_Solver *solv, Id problem);
extern const char *solver_solutionelement2str(struct s_Solver *solv, Id p, Id rp);

#ifdef __cplusplus
}
#endif

#endif
