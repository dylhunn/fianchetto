#ifndef SETTINGS_H
#define SETTINGS_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "stdbool.h"
#include "types.h"

/*
 * Search settings
 * Some settings use the preprocessor to ensure the optimizer catches them as constants.
 */
static const bool use_mtd_f = true; // Use MTD-F optimization on top of alpha-beta search; use_ttable must also be on
static const int quiesce_ply_cutoff = 45; // Quiescence search will cut off after this many plies
#define mvvlva true // Capture hueristic
#define use_qsearch true // Quiescence search
static const bool clear_tt_every_move = false; // Clear the transposition table after each search completes
#define use_ttable true // Should the transposition table be used to generate search cutoffs?
#define use_hash_option false // Allow the uci interface to set the tt size
static const bool use_tt_move_hueristic = true; // Use the last move stored in the TT as a "best-first" hueristic
static const bool check_extend = false; // Extend the search by one ply in case of check
static const int check_extension_centiply = 100; // Centiply to extend in case of check
static const int check_extend_threshold = 2; // In the final n plies of regular search
static const bool use_log_file = true;
static const bool always_use_debug_mode = false;
//static const int num_search_threads = 1; // Parallel search
static const int frontier_futility_margin = 310;
static const int prefrontier_futility_margin = 510;
#define use_futility_pruning true

/*
 * Evaluation settings
 */
static const int doubled_pawn_penalty = 13; // Evaluation penalties for doubled pawns
static const int bishop_pair_bonus = 20;

/*
 * Transposition Table settings
 */
#define TT_MEGABYTES_DEFAULT 1000
static const double tt_max_load = .70;
// Nodes that haven't been accessed in this many moves are ancient and might be removed
static const int remove_at_age = 3; // TODO dynamically select?

/*
 * Engine settings
 */
#define ENGINE_NAME "Sabertooth"
#define ENGINE_VERSION "0.1.4b"
#define AUTHOR_NAME "Dylan D. Hunn"

/*
 * UCI protocol settings
 */
#define max_input_string_length 2000
#define iterative_deepening_cutoff 40 // Cutoff is necessary to prevent very deep sarches in the event of mate
#define pv_printing_cutoff 40 // Cutoff is nessary to avoid printing cyclic PVs forever

#endif

