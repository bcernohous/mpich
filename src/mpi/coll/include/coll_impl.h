/* -*- Mode: C; c-basic-offset:4 ; indent-tabs-mode:nil ; -*- */
/*
 *  (C) 2006 by Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 *
 *  Portions of this code were written by Intel Corporation.
 *  Copyright (C) 2011-2017 Intel Corporation.  Intel provides this material
 *  to Argonne National Laboratory subject to Software Grant and Corporate
 *  Contributor License Agreement dated February 8, 2012.
 */

#ifndef MPIR_COLL_IMPL_H_INCLUDED
#define MPIR_COLL_IMPL_H_INCLUDED

/* Enumerate the list of algorithms */
typedef enum MPIR_Allgather_intra_algo_t {
    MPIR_ALLGATHER_INTRA_ALGO_AUTO,
    MPIR_ALLGATHER_INTRA_ALGO_BRUCKS,
    MPIR_ALLGATHER_INTRA_ALGO_RECURSIVE_DOUBLING,
    MPIR_ALLGATHER_INTRA_ALGO_RING
} MPIR_Allgather_intra_algo_t;
/* Have an easy way of finding the algorithm choice later without doing string
 * comparisons */
extern int MPIR_Allgather_intra_algo_choice;

typedef enum MPIR_Allgather_inter_algo_t {
    MPIR_ALLGATHER_INTER_ALGO_GENERIC,
    MPIR_ALLGATHER_INTER_ALGO_AUTO
} MPIR_Allgather_inter_algo_t;
extern int MPIR_Allgather_inter_algo_choice;

typedef enum MPIR_Allgatherv_intra_algo_t {
    MPIR_ALLGATHERV_INTRA_ALGO_AUTO,
    MPIR_ALLGATHERV_INTRA_ALGO_BRUCKS,
    MPIR_ALLGATHERV_INTRA_ALGO_RECURSIVE_DOUBLING,
    MPIR_ALLGATHERV_INTRA_ALGO_RING
} MPIR_Allgatherv_intra_algo_t;
extern int MPIR_Allgatherv_intra_algo_choice;

typedef enum MPIR_Allgatherv_inter_algo_t {
    MPIR_ALLGATHERV_INTER_ALGO_GENERIC,
    MPIR_ALLGATHERV_INTER_ALGO_AUTO
} MPIR_Allgatherv_inter_algo_t;
extern int MPIR_Allgatherv_inter_algo_choice;

typedef enum MPIR_Allreduce_intra_algo_t {
    MPIR_ALLREDUCE_INTRA_ALGO_AUTO,
    MPIR_ALLREDUCE_INTRA_ALGO_RECURSIVE_DOUBLING,
    MPIR_ALLREDUCE_INTRA_ALGO_REDSCAT_ALLGATHER
} MPIR_Allreduce_intra_algo_t;
extern int MPIR_Allreduce_intra_algo_choice;

typedef enum MPIR_Allreduce_inter_algo_t {
    MPIR_ALLREDUCE_INTER_ALGO_GENERIC,
    MPIR_ALLREDUCE_INTER_ALGO_AUTO
} MPIR_Allreduce_inter_algo_t;
extern int MPIR_Allreduce_inter_algo_choice;

typedef enum MPIR_Alltoall_intra_algo_t {
    MPIR_ALLTOALL_INTRA_ALGO_AUTO,
    MPIR_ALLTOALL_INTRA_ALGO_BRUCKS,
    MPIR_ALLTOALL_INTRA_ALGO_PAIRWISE,
    MPIR_ALLTOALL_INTRA_ALGO_PAIRWISE_SENDRECV_REPLACE,
    MPIR_ALLTOALL_INTRA_ALGO_SCATTERED
} MPIR_Alltoall_intra_algo_t;
extern int MPIR_Alltoall_intra_algo_choice;

typedef enum MPIR_Alltoall_inter_algo_t {
    MPIR_ALLTOALL_INTER_ALGO_GENERIC,
    MPIR_ALLTOALL_INTER_ALGO_AUTO
} MPIR_Alltoall_inter_algo_t;
extern int MPIR_Alltoall_inter_algo_choice;

typedef enum MPIR_Alltoallv_intra_algo_t {
    MPIR_ALLTOALLV_INTRA_ALGO_AUTO,
    MPIR_ALLTOALLV_INTRA_ALGO_PAIRWISE_SENDRECV_REPLACE,
    MPIR_ALLTOALLV_INTRA_ALGO_SCATTERED
} MPIR_Alltoallv_intra_algo_t;
extern int MPIR_Alltoallv_intra_algo_choice;

typedef enum MPIR_Alltoallv_inter_algo_t {
    MPIR_ALLTOALLV_INTER_ALGO_GENERIC,
    MPIR_ALLTOALLV_INTER_ALGO_AUTO
} MPIR_Alltoallv_inter_algo_t;
extern int MPIR_Alltoallv_inter_algo_choice;

typedef enum MPIR_Alltoallw_intra_algo_t {
    MPIR_ALLTOALLW_INTRA_ALGO_AUTO,
    MPIR_ALLTOALLW_INTRA_ALGO_PAIRWISE_SENDRECV_REPLACE,
    MPIR_ALLTOALLW_INTRA_ALGO_SCATTERED
} MPIR_Alltoallw_intra_algo_t;
extern int MPIR_Alltoallw_intra_algo_choice;

typedef enum MPIR_Alltoallw_inter_algo_t {
    MPIR_ALLTOALLW_INTER_ALGO_GENERIC,
    MPIR_ALLTOALLW_INTER_ALGO_AUTO
} MPIR_Alltoallw_inter_algo_t;
extern int MPIR_Alltoallw_inter_algo_choice;

typedef enum MPIR_Barrier_intra_algo_t {
    MPIR_BARRIER_INTRA_ALGO_AUTO,
    MPIR_BARRIER_INTRA_ALGO_RECURSIVE_DOUBLING
} MPIR_Barrier_intra_algo_t;
extern int MPIR_Barrier_intra_algo_choice;

typedef enum MPIR_Barrier_inter_algo_t {
    MPIR_BARRIER_INTER_ALGO_GENERIC,
    MPIR_BARRIER_INTER_ALGO_AUTO
} MPIR_Barrier_inter_algo_t;
extern int MPIR_Barrier_inter_algo_choice;

typedef enum MPIR_Bcast_intra_algo_t {
    MPIR_BCAST_INTRA_ALGO_AUTO,
    MPIR_BCAST_INTRA_ALGO_BINOMIAL,
    MPIR_BCAST_INTRA_ALGO_SCATTER_DOUBLING_ALLGATHER,
    MPIR_BCAST_INTRA_ALGO_SCATTER_RING_ALLGATHER
} MPIR_Bcast_intra_algo_t;
extern int MPIR_Bcast_intra_algo_choice;

typedef enum MPIR_Bcast_inter_algo_t {
    MPIR_BCAST_INTER_ALGO_GENERIC,
    MPIR_BCAST_INTER_ALGO_AUTO
} MPIR_Bcast_inter_algo_t;
extern int MPIR_Bcast_inter_algo_choice;

typedef enum MPIR_Exscan_intra_algo_t {
    MPIR_EXSCAN_INTRA_ALGO_AUTO,
    MPIR_EXSCAN_INTRA_ALGO_RECURSIVE_DOUBLING,
} MPIR_Exscan_intra_algo_t;
extern int MPIR_Exscan_intra_algo_choice;

typedef enum MPIR_Gather_intra_algo_t {
    MPIR_GATHER_INTRA_ALGO_AUTO,
    MPIR_GATHER_INTRA_ALGO_BINOMIAL
} MPIR_Gather_intra_algo_t;
extern int MPIR_Gather_intra_algo_choice;

typedef enum MPIR_Gather_inter_algo_t {
    MPIR_GATHER_INTER_ALGO_GENERIC,
    MPIR_GATHER_INTER_ALGO_AUTO
} MPIR_Gather_inter_algo_t;
extern int MPIR_Gather_inter_algo_choice;

typedef enum MPIR_Gatherv_intra_algo_t {
    MPIR_GATHERV_INTRA_ALGO_AUTO,
    MPIR_GATHERV_INTRA_ALGO_LINEAR
} MPIR_Gatherv_intra_algo_t;
extern int MPIR_Gatherv_intra_algo_choice;

typedef enum MPIR_Gatherv_inter_algo_t {
    MPIR_GATHERV_INTER_ALGO_AUTO,
    MPIR_GATHERV_INTER_ALGO_LINEAR
} MPIR_Gatherv_inter_algo_t;
extern int MPIR_Gatherv_inter_algo_choice;

typedef enum MPIR_Iallgather_intra_algo_t {
    MPIR_IALLGATHER_INTRA_ALGO_AUTO,
    MPIR_IALLGATHER_INTRA_ALGO_BRUCKS,
    MPIR_IALLGATHER_INTRA_ALGO_RECURSIVE_DOUBLING,
    MPIR_IALLGATHER_INTRA_ALGO_RING
} MPIR_Iallgather_intra_algo_t;
extern int MPIR_Iallgather_intra_algo_choice;

typedef enum MPIR_Iallgather_inter_algo_t {
    MPIR_IALLGATHER_INTER_ALGO_GENERIC,
    MPIR_IALLGATHER_INTER_ALGO_AUTO
} MPIR_Iallgather_inter_algo_t;
extern int MPIR_Iallgather_inter_algo_choice;

typedef enum MPIR_Iallgatherv_intra_algo_t {
    MPIR_IALLGATHERV_INTRA_ALGO_AUTO,
    MPIR_IALLGATHERV_INTRA_ALGO_BRUCKS,
    MPIR_IALLGATHERV_INTRA_ALGO_RECURSIVE_DOUBLING,
    MPIR_IALLGATHERV_INTRA_ALGO_RING
} MPIR_Iallgatherv_intra_algo_t;
extern int MPIR_Iallgatherv_intra_algo_choice;

typedef enum MPIR_Iallgatherv_inter_algo_t {
    MPIR_IALLGATHERV_INTER_ALGO_GENERIC,
    MPIR_IALLGATHERV_INTER_ALGO_AUTO
} MPIR_Iallgatherv_inter_algo_t;
extern int MPIR_Iallgatherv_inter_algo_choice;

typedef enum MPIR_Iallreduce_intra_algo_t {
    MPIR_IALLREDUCE_INTRA_ALGO_AUTO,
    MPIR_IALLREDUCE_INTRA_ALGO_NAIVE,
    MPIR_IALLREDUCE_INTRA_ALGO_RECURSIVE_DOUBLING,
    MPIR_IALLREDUCE_INTRA_ALGO_REDSCAT_ALLGATHER
} MPIR_Iallreduce_intra_algo_t;
extern int MPIR_Iallreduce_intra_algo_choice;

typedef enum MPIR_Iallreduce_inter_algo_t {
    MPIR_IALLREDUCE_INTER_ALGO_GENERIC,
    MPIR_IALLREDUCE_INTER_ALGO_AUTO
} MPIR_Iallreduce_inter_algo_t;
extern int MPIR_Iallreduce_inter_algo_choice;

typedef enum MPIR_Ialltoall_intra_algo_t {
    MPIR_IALLTOALL_INTRA_ALGO_AUTO,
    MPIR_IALLTOALL_INTRA_ALGO_BRUCKS,
    MPIR_IALLTOALL_INTRA_ALGO_INPLACE,
    MPIR_IALLTOALL_INTRA_ALGO_PAIRWISE,
    MPIR_IALLTOALL_INTRA_ALGO_PERM_SR
} MPIR_Ialltoall_intra_algo_t;
extern int MPIR_Ialltoall_intra_algo_choice;

typedef enum MPIR_Ialltoall_inter_algo_t {
    MPIR_IALLTOALL_INTER_ALGO_GENERIC,
    MPIR_IALLTOALL_INTER_ALGO_AUTO
} MPIR_Ialltoall_inter_algo_t;
extern int MPIR_Ialltoall_inter_algo_choice;

typedef enum MPIR_Ialltoallv_intra_algo_t {
    MPIR_IALLTOALLV_INTRA_ALGO_AUTO,
    MPIR_IALLTOALLV_INTRA_ALGO_BLOCKED,
    MPIR_IALLTOALLV_INTRA_ALGO_INPLACE
} MPIR_Ialltoallv_intra_algo_t;
extern int MPIR_Ialltoallv_intra_algo_choice;

typedef enum MPIR_Ialltoallv_inter_algo_t {
    MPIR_IALLTOALLV_INTER_ALGO_AUTO,
    MPIR_IALLTOALLV_INTER_ALGO_PAIRWISE_XCHG
} MPIR_Ialltoallv_inter_algo_t;
extern int MPIR_Ialltoallv_inter_algo_choice;

typedef enum MPIR_Ialltoallw_intra_algo_t {
    MPIR_IALLTOALLW_INTRA_ALGO_AUTO,
    MPIR_IALLTOALLW_INTRA_ALGO_BLOCKED,
    MPIR_IALLTOALLW_INTRA_ALGO_INPLACE
} MPIR_Ialltoallw_intra_algo_t;
extern int MPIR_Ialltoallw_intra_algo_choice;

typedef enum MPIR_Ialltoallw_inter_algo_t {
    MPIR_IALLTOALLW_INTER_ALGO_AUTO,
    MPIR_IALLTOALLW_INTER_ALGO_PAIRWISE_XCHG
} MPIR_Ialltoallw_inter_algo_t;
extern int MPIR_Ialltoallw_inter_algo_choice;

typedef enum MPIR_Ibarrier_intra_algo_t {
    MPIR_IBARRIER_INTRA_ALGO_AUTO,
    MPIR_IBARRIER_INTRA_ALGO_RECURSIVE_DOUBLING
} MPIR_Ibarrier_intra_algo_t;
extern int MPIR_Ibarrier_intra_algo_choice;

typedef enum MPIR_Ibarrier_inter_algo_t {
    MPIR_IBARRIER_INTER_ALGO_AUTO,
    MPIR_IBARRIER_INTER_ALGO_BCAST
} MPIR_Ibarrier_inter_algo_t;
extern int MPIR_Ibarrier_inter_algo_choice;

typedef enum MPIR_Ibcast_intra_algo_t {
    MPIR_IBCAST_INTRA_ALGO_AUTO,
    MPIR_IBCAST_INTRA_ALGO_BINOMIAL
} MPIR_Ibcast_intra_algo_t;
extern int MPIR_Ibcast_intra_algo_choice;

typedef enum MPIR_Ibcast_inter_algo_t {
    MPIR_IBCAST_INTER_ALGO_AUTO,
    MPIR_IBCAST_INTER_ALGO_FLAT
} MPIR_Ibcast_inter_algo_t;
extern int MPIR_Ibcast_inter_algo_choice;

typedef enum MPIR_Iexscan_intra_algo_t {
    MPIR_IEXSCAN_INTRA_ALGO_AUTO,
    MPIR_IEXSCAN_INTRA_ALGO_RECURSIVE_DOUBLING
} MPIR_Iexscan_intra_algo_t;
extern int MPIR_Iexscan_intra_algo_choice;

typedef enum MPIR_Igather_intra_algo_t {
    MPIR_IGATHER_INTRA_ALGO_AUTO,
    MPIR_IGATHER_INTRA_ALGO_BINOMIAL
} MPIR_Igather_intra_algo_t;
extern int MPIR_Igather_intra_algo_choice;

typedef enum MPIR_Igather_inter_algo_t {
    MPIR_IGATHER_INTER_ALGO_AUTO,
    MPIR_IGATHER_INTER_ALGO_LONG,
    MPIR_IGATHER_INTER_ALGO_SHORT
} MPIR_Igather_inter_algo_t;
extern int MPIR_Igather_inter_algo_choice;

typedef enum MPIR_Igatherv_intra_algo_t {
    MPIR_IGATHERV_INTRA_ALGO_AUTO,
    MPIR_IGATHERV_INTRA_ALGO_GENERIC
} MPIR_Igatherv_intra_algo_t;
extern int MPIR_Igatherv_intra_algo_choice;

typedef enum MPIR_Igatherv_inter_algo_t {
    MPIR_IGATHERV_INTER_ALGO_AUTO,
    MPIR_IGATHERV_INTER_ALGO_GENERIC
} MPIR_Igatherv_inter_algo_t;
extern int MPIR_Igatherv_inter_algo_choice;

typedef enum MPIR_Ineighbor_allgather_intra_algo_t {
    MPIR_INEIGHBOR_ALLGATHER_INTRA_ALGO_AUTO,
    MPIR_INEIGHBOR_ALLGATHER_INTRA_ALGO_GENERIC
} MPIR_Ineighbor_allgather_intra_algo_t;
extern int MPIR_Ineighbor_allgather_intra_algo_choice;

typedef enum MPIR_Ineighbor_allgather_inter_algo_t {
    MPIR_INEIGHBOR_ALLGATHER_INTER_ALGO_AUTO,
    MPIR_INEIGHBOR_ALLGATHER_INTER_ALGO_GENERIC
} MPIR_Ineighbor_allgather_inter_algo_t;
extern int MPIR_Ineighbor_allgather_inter_algo_choice;

typedef enum MPIR_Ineighbor_allgatherv_intra_algo_t {
    MPIR_INEIGHBOR_ALLGATHERV_INTRA_ALGO_AUTO,
    MPIR_INEIGHBOR_ALLGATHERV_INTRA_ALGO_GENERIC
} MPIR_Ineighbor_allgatherv_intra_algo_t;
extern int MPIR_Ineighbor_allgatherv_intra_algo_choice;

typedef enum MPIR_Ineighbor_allgatherv_inter_algo_t {
    MPIR_INEIGHBOR_ALLGATHERV_INTER_ALGO_AUTO,
    MPIR_INEIGHBOR_ALLGATHERV_INTER_ALGO_GENERIC
} MPIR_Ineighbor_allgatherv_inter_algo_t;
extern int MPIR_Ineighbor_allgatherv_inter_algo_choice;

typedef enum MPIR_Ineighbor_alltoall_intra_algo_t {
    MPIR_INEIGHBOR_ALLTOALL_INTRA_ALGO_AUTO,
    MPIR_INEIGHBOR_ALLTOALL_INTRA_ALGO_GENERIC
} MPIR_Ineighbor_alltoall_intra_algo_t;
extern int MPIR_Ineighbor_alltoall_intra_algo_choice;

typedef enum MPIR_Ineighbor_alltoall_inter_algo_t {
    MPIR_INEIGHBOR_ALLTOALL_INTER_ALGO_AUTO,
    MPIR_INEIGHBOR_ALLTOALL_INTER_ALGO_GENERIC
} MPIR_Ineighbor_alltoall_inter_algo_t;
extern int MPIR_Ineighbor_alltoall_inter_algo_choice;

typedef enum MPIR_Ineighbor_alltoallv_intra_algo_t {
    MPIR_INEIGHBOR_ALLTOALLV_INTRA_ALGO_AUTO,
    MPIR_INEIGHBOR_ALLTOALLV_INTRA_ALGO_GENERIC
} MPIR_Ineighbor_alltoallv_intra_algo_t;
extern int MPIR_Ineighbor_alltoallv_intra_algo_choice;

typedef enum MPIR_Ineighbor_alltoallv_inter_algo_t {
    MPIR_INEIGHBOR_ALLTOALLV_INTER_ALGO_AUTO,
    MPIR_INEIGHBOR_ALLTOALLV_INTER_ALGO_GENERIC
} MPIR_Ineighbor_alltoallv_inter_algo_t;
extern int MPIR_Ineighbor_alltoallv_inter_algo_choice;

typedef enum MPIR_Ineighbor_alltoallw_intra_algo_t {
    MPIR_INEIGHBOR_ALLTOALLW_INTRA_ALGO_AUTO,
    MPIR_INEIGHBOR_ALLTOALLW_INTRA_ALGO_GENERIC
} MPIR_Ineighbor_alltoallw_intra_algo_t;
extern int MPIR_Ineighbor_alltoallw_intra_algo_choice;

typedef enum MPIR_Ineighbor_alltoallw_inter_algo_t {
    MPIR_INEIGHBOR_ALLTOALLW_INTER_ALGO_AUTO,
    MPIR_INEIGHBOR_ALLTOALLW_INTER_ALGO_GENERIC
} MPIR_Ineighbor_alltoallw_inter_algo_t;
extern int MPIR_Ineighbor_alltoallw_inter_algo_choice;

typedef enum MPIR_Ireduce_scatter_intra_algo_t {
    MPIR_IREDUCE_SCATTER_INTRA_ALGO_AUTO,
    MPIR_IREDUCE_SCATTER_INTRA_ALGO_NONCOMM,
    MPIR_IREDUCE_SCATTER_INTRA_ALGO_PAIRWISE,
    MPIR_IREDUCE_SCATTER_INTRA_ALGO_RECURSIVE_DOUBLING,
    MPIR_IREDUCE_SCATTER_INTRA_ALGO_RECURSIVE_HALVING
} MPIR_Ireduce_scatter_intra_algo_t;
extern int MPIR_Ireduce_scatter_intra_algo_choice;

typedef enum MPIR_Ireduce_scatter_inter_algo_t {
    MPIR_IREDUCE_SCATTER_INTER_ALGO_AUTO,
    MPIR_IREDUCE_SCATTER_INTER_ALGO_GENERIC
} MPIR_Ireduce_scatter_inter_algo_t;
extern int MPIR_Ireduce_scatter_inter_algo_choice;

typedef enum MPIR_Ireduce_scatter_block_intra_algo_t {
    MPIR_IREDUCE_SCATTER_BLOCK_INTRA_ALGO_AUTO,
    MPIR_IREDUCE_SCATTER_BLOCK_INTRA_ALGO_NONCOMM,
    MPIR_IREDUCE_SCATTER_BLOCK_INTRA_ALGO_PAIRWISE,
    MPIR_IREDUCE_SCATTER_BLOCK_INTRA_ALGO_RECURSIVE_DOUBLING,
    MPIR_IREDUCE_SCATTER_BLOCK_INTRA_ALGO_RECURSIVE_HALVING
} MPIR_Ireduce_scatter_block_intra_algo_t;
extern int MPIR_Ireduce_scatter_block_intra_algo_choice;

typedef enum MPIR_Ireduce_scatter_block_inter_algo_t {
    MPIR_IREDUCE_SCATTER_BLOCK_INTER_ALGO_AUTO,
    MPIR_IREDUCE_SCATTER_BLOCK_INTER_ALGO_GENERIC
} MPIR_Ireduce_scatter_block_inter_algo_t;
extern int MPIR_Ireduce_scatter_block_inter_algo_choice;

typedef enum MPIR_Ireduce_intra_algo_t {
    MPIR_IREDUCE_INTRA_ALGO_AUTO,
    MPIR_IREDUCE_INTRA_ALGO_BINOMIAL,
    MPIR_IREDUCE_INTRA_ALGO_REDSCAT_GATHER
} MPIR_Ireduce_intra_algo_t;
extern int MPIR_Ireduce_intra_algo_choice;

typedef enum MPIR_Ireduce_inter_algo_t {
    MPIR_IREDUCE_INTER_ALGO_GENERIC,
    MPIR_IREDUCE_INTER_ALGO_AUTO
} MPIR_Ireduce_inter_algo_t;
extern int MPIR_Ireduce_inter_algo_choice;

typedef enum MPIR_Iscan_intra_algo_t {
    MPIR_ISCAN_INTRA_ALGO_AUTO,
    MPIR_ISCAN_INTRA_ALGO_RECURSIVE_DOUBLING
} MPIR_Iscan_intra_algo_t;
extern int MPIR_Iscan_intra_algo_choice;

typedef enum MPIR_Iscatter_intra_algo_t {
    MPIR_ISCATTER_INTRA_ALGO_AUTO,
    MPIR_ISCATTER_INTRA_ALGO_BINOMIAL
} MPIR_Iscatter_intra_algo_t;
extern int MPIR_Iscatter_intra_algo_choice;

typedef enum MPIR_Iscatter_inter_algo_t {
    MPIR_ISCATTER_INTER_ALGO_GENERIC,
    MPIR_ISCATTER_INTER_ALGO_AUTO
} MPIR_Iscatter_inter_algo_t;
extern int MPIR_Iscatter_inter_algo_choice;

typedef enum MPIR_Iscatterv_intra_algo_t {
    MPIR_ISCATTERV_INTRA_ALGO_AUTO,
    MPIR_ISCATTERV_INTRA_ALGO_LINEAR
} MPIR_Iscatterv_intra_algo_t;
extern int MPIR_Iscatterv_intra_algo_choice;

typedef enum MPIR_Iscatterv_inter_algo_t {
    MPIR_ISCATTERV_INTER_ALGO_AUTO,
    MPIR_ISCATTERV_INTER_ALGO_LINEAR
} MPIR_Iscatterv_inter_algo_t;
extern int MPIR_Iscatterv_inter_algo_choice;

typedef enum MPIR_Neighbor_allgather_intra_algo_t {
    MPIR_NEIGHBOR_ALLGATHER_INTRA_ALGO_AUTO,
    MPIR_NEIGHBOR_ALLGATHER_INTRA_ALGO_NB
} MPIR_Neighbor_allgather_intra_algo_t;
extern int MPIR_Neighbor_allgather_intra_algo_choice;

typedef enum MPIR_Neighbor_allgather_inter_algo_t {
    MPIR_NEIGHBOR_ALLGATHER_INTER_ALGO_AUTO,
    MPIR_NEIGHBOR_ALLGATHER_INTER_ALGO_NB
} MPIR_Neighbor_allgather_inter_algo_t;
extern int MPIR_Neighbor_allgather_inter_algo_choice;

typedef enum MPIR_Neighbor_allgatherv_intra_algo_t {
    MPIR_NEIGHBOR_ALLGATHERV_INTRA_ALGO_AUTO,
    MPIR_NEIGHBOR_ALLGATHERV_INTRA_ALGO_NB
} MPIR_Neighbor_allgatherv_intra_algo_t;
extern int MPIR_Neighbor_allgatherv_intra_algo_choice;

typedef enum MPIR_Neighbor_allgatherv_inter_algo_t {
    MPIR_NEIGHBOR_ALLGATHERV_INTER_ALGO_AUTO,
    MPIR_NEIGHBOR_ALLGATHERV_INTER_ALGO_NB
} MPIR_Neighbor_allgatherv_inter_algo_t;
extern int MPIR_Neighbor_allgatherv_inter_algo_choice;

typedef enum MPIR_Neighbor_alltoall_intra_algo_t {
    MPIR_NEIGHBOR_ALLTOALL_INTRA_ALGO_AUTO,
    MPIR_NEIGHBOR_ALLTOALL_INTRA_ALGO_NB
} MPIR_Neighbor_alltoall_intra_algo_t;
extern int MPIR_Neighbor_alltoall_intra_algo_choice;

typedef enum MPIR_Neighbor_alltoall_inter_algo_t {
    MPIR_NEIGHBOR_ALLTOALL_INTER_ALGO_AUTO,
    MPIR_NEIGHBOR_ALLTOALL_INTER_ALGO_NB
} MPIR_Neighbor_alltoall_inter_algo_t;
extern int MPIR_Neighbor_alltoall_inter_algo_choice;

typedef enum MPIR_Neighbor_alltoallv_intra_algo_t {
    MPIR_NEIGHBOR_ALLTOALLV_INTRA_ALGO_AUTO,
    MPIR_NEIGHBOR_ALLTOALLV_INTRA_ALGO_NB
} MPIR_Neighbor_alltoallv_intra_algo_t;
extern int MPIR_Neighbor_alltoallv_intra_algo_choice;

typedef enum MPIR_Neighbor_alltoallv_inter_algo_t {
    MPIR_NEIGHBOR_ALLTOALLV_INTER_ALGO_AUTO,
    MPIR_NEIGHBOR_ALLTOALLV_INTER_ALGO_NB
} MPIR_Neighbor_alltoallv_inter_algo_t;
extern int MPIR_Neighbor_alltoallv_inter_algo_choice;

typedef enum MPIR_Neighbor_alltoallw_intra_algo_t {
    MPIR_NEIGHBOR_ALLTOALLW_INTRA_ALGO_AUTO,
    MPIR_NEIGHBOR_ALLTOALLW_INTRA_ALGO_NB
} MPIR_Neighbor_alltoallw_intra_algo_t;
extern int MPIR_Neighbor_alltoallw_intra_algo_choice;

typedef enum MPIR_Neighbor_alltoallw_inter_algo_t {
    MPIR_NEIGHBOR_ALLTOALLW_INTER_ALGO_AUTO,
    MPIR_NEIGHBOR_ALLTOALLW_INTER_ALGO_NB
} MPIR_Neighbor_alltoallw_inter_algo_t;
extern int MPIR_Neighbor_alltoallw_inter_algo_choice;

typedef enum MPIR_Reduce_scatter_intra_algo_t {
    MPIR_REDUCE_SCATTER_INTRA_ALGO_AUTO,
    MPIR_REDUCE_SCATTER_INTRA_ALGO_NONCOMM,
    MPIR_REDUCE_SCATTER_INTRA_ALGO_PAIRWISE,
    MPIR_REDUCE_SCATTER_INTRA_ALGO_RECURSIVE_DOUBLING,
    MPIR_REDUCE_SCATTER_INTRA_ALGO_RECURSIVE_HALVING
} MPIR_Reduce_scatter_intra_algo_t;
extern int MPIR_Reduce_scatter_intra_algo_choice;

typedef enum MPIR_Reduce_scatter_inter_algo_t {
    MPIR_REDUCE_SCATTER_INTER_ALGO_GENERIC,
    MPIR_REDUCE_SCATTER_INTER_ALGO_AUTO
} MPIR_Reduce_scatter_inter_algo_t;
extern int MPIR_Reduce_scatter_inter_algo_choice;

typedef enum MPIR_Reduce_scatter_block_intra_algo_t {
    MPIR_REDUCE_SCATTER_BLOCK_INTRA_ALGO_AUTO,
    MPIR_REDUCE_SCATTER_BLOCK_INTRA_ALGO_NONCOMM,
    MPIR_REDUCE_SCATTER_BLOCK_INTRA_ALGO_PAIRWISE,
    MPIR_REDUCE_SCATTER_BLOCK_INTRA_ALGO_RECURSIVE_DOUBLING,
    MPIR_REDUCE_SCATTER_BLOCK_INTRA_ALGO_RECURSIVE_HALVING
} MPIR_Reduce_scatter_block_intra_algo_t;
extern int MPIR_Reduce_scatter_block_intra_algo_choice;

typedef enum MPIR_Reduce_scatter_block_inter_algo_t {
    MPIR_REDUCE_SCATTER_BLOCK_INTER_ALGO_GENERIC,
    MPIR_REDUCE_SCATTER_BLOCK_INTER_ALGO_AUTO
} MPIR_Reduce_scatter_block_inter_algo_t;
extern int MPIR_Reduce_scatter_block_inter_algo_choice;

typedef enum MPIR_Reduce_intra_algo_t {
    MPIR_REDUCE_INTRA_ALGO_AUTO,
    MPIR_REDUCE_INTRA_ALGO_BINOMIAL,
    MPIR_REDUCE_INTRA_ALGO_REDSCAT_GATHER
} MPIR_Reduce_intra_algo_t;
extern int MPIR_Reduce_intra_algo_choice;

typedef enum MPIR_Reduce_inter_algo_t {
    MPIR_REDUCE_INTER_ALGO_GENERIC,
    MPIR_REDUCE_INTER_ALGO_AUTO
} MPIR_Reduce_inter_algo_t;
extern int MPIR_Reduce_inter_algo_choice;

typedef enum MPIR_Scan_intra_algo_t {
    MPIR_SCAN_INTRA_ALGO_AUTO,
    MPIR_SCAN_INTRA_ALGO_GENERIC
} MPIR_Scan_intra_algo_t;
extern int MPIR_Scan_intra_algo_choice;

typedef enum MPIR_Scatter_intra_algo_t {
    MPIR_SCATTER_INTRA_ALGO_AUTO,
    MPIR_SCATTER_INTRA_ALGO_BINOMIAL
} MPIR_Scatter_intra_algo_t;
extern int MPIR_Scatter_intra_algo_choice;

typedef enum MPIR_Scatter_inter_algo_t {
    MPIR_SCATTER_INTER_ALGO_GENERIC,
    MPIR_SCATTER_INTER_ALGO_AUTO
} MPIR_Scatter_inter_algo_t;
extern int MPIR_Scatter_inter_algo_choice;

typedef enum MPIR_Scatterv_intra_algo_t {
    MPIR_SCATTERV_INTRA_ALGO_AUTO,
    MPIR_SCATTERV_INTRA_ALGO_LINEAR
} MPIR_Scatterv_intra_algo_t;
extern int MPIR_Scatterv_intra_algo_choice;

typedef enum MPIR_Scatterv_inter_algo_t {
    MPIR_SCATTERV_INTER_ALGO_AUTO,
    MPIR_SCATTERV_INTER_ALGO_LINEAR
} MPIR_Scatterv_inter_algo_t;
extern int MPIR_Scatterv_inter_algo_choice;

int MPIR_COLL_init(void);

#endif /* MPIR_COLL_IMPL_H_INCLUDED */