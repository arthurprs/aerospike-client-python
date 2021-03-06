/*******************************************************************************
 * Copyright 2013-2015 Aerospike, Inc.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 ******************************************************************************/

#pragma once

#include <Python.h>
#include <stdbool.h>

#include <aerospike/aerospike.h>
#include <aerospike/as_key.h>
#include <aerospike/as_query.h>
#include <aerospike/as_scan.h>
#include <aerospike/as_bin.h>
#include <aerospike/as_ldt.h>
#include "pool.h"

// Bin names can be of type Unicode in Python
// DB supports 32767 maximum number of bins
#define MAX_UNICODE_OBJECTS 32767

typedef struct {
	PyObject *ob[MAX_UNICODE_OBJECTS];
	int size;
} UnicodePyObjects;

typedef struct {
	PyObject_HEAD
	aerospike * as;
	int is_conn_16;
} AerospikeClient;

typedef struct {
	PyObject_HEAD
	AerospikeClient * client;
	PyObject * namespace;
	PyObject * set;
	PyObject * key;
} AerospikeKey;

typedef struct {
	PyObject_HEAD
	AerospikeClient * client;
	as_query query;
	as_static_pool static_pool;
	UnicodePyObjects u_objs;
} AerospikeQuery;

typedef struct {
  PyObject_HEAD
  AerospikeClient * client;
  as_scan scan;
} AerospikeScan;

typedef struct {
    PyObject_HEAD
    AerospikeClient * client;
    as_ldt lstack;
    as_key key;
    char bin_name[AS_BIN_NAME_MAX_LEN];
} AerospikeLStack;

typedef struct {
    PyObject_HEAD
    AerospikeClient * client;
    as_ldt lset;
    as_key key;
    char bin_name[AS_BIN_NAME_MAX_LEN];
} AerospikeLSet;

typedef struct {
    PyObject_HEAD
    AerospikeClient * client;
    as_ldt llist;
    as_key key;
    char bin_name[AS_BIN_NAME_MAX_LEN];
} AerospikeLList;

typedef struct {
    PyObject_HEAD
    AerospikeClient * client;
    as_ldt lmap;
    as_key key;
    char bin_name[AS_BIN_NAME_MAX_LEN];
} AerospikeLMap;
