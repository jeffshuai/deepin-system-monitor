/*
* Copyright (C) 2019 ~ 2021 Uniontech Software Technology Co.,Ltd.
*
* Author:     xuezifan<xuezifan@uniontech.com>
*
* Maintainer: xuezifan<xuezifan@uniontech.com>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

//self
#include "common/hash.h"
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <endian.h>

//gtest
#include "stub.h"
#include <gtest/gtest.h>

//qt
#include <sys/time.h>
#include <QApplication>
#include <QDateTime>

using namespace util;
using namespace common;
/***************************************STUB begin*********************************************/

/***************************************STUB end**********************************************/

TEST(UT_Hash, test_hash_x86_32_01)
{
    uint32_t out1 = 4;
    uint8_t value[10] {};
    for (int i = 0; i < 10; i++) {
        value[i] = uint8_t(i);
    }
    uint8_t *key = value;
    int len = 4;
    uint32_t seed = 5;
    uint32_t *out = &out1;
    hash_x86_32(key,len,seed,out);
}

TEST(UT_Hash, test_hash_x86_32_02)
{
    uint32_t out1 = 4;
    uint8_t value[10] {};
    for (int i = 0; i < 10; i++) {
        value[i] = uint8_t(i);
    }
    uint8_t *key = value;
    int len = 3;
    uint32_t seed = 5;
    uint32_t *out = &out1;
    hash_x86_32(key,len,seed,out);
}

TEST(UT_Hash, test_hash_x86_32_03)
{
    uint32_t out1 = 4;
    uint8_t value[10] {};
    for (int i = 0; i < 10; i++) {
        value[i] = uint8_t(i);
    }
    uint8_t *key = value;
    int len = 2;
    uint32_t seed = 5;
    uint32_t *out = &out1;
    hash_x86_32(key,len,seed,out);
}

TEST(UT_Hash, test_hash_x86_32_04)
{
    uint32_t out1 = 4;
    uint8_t value[10] {};
    for (int i = 0; i < 10; i++) {
        value[i] = uint8_t(i);
    }
    uint8_t *key = value;
    int len = 1;
    uint32_t seed = 5;
    uint32_t *out = &out1;
    hash_x86_32(key,len,seed,out);
}


TEST(UT_Hash, test_hash_x86_128_01)
{
    uint8_t value[100] {};
    for (int i = 0; i < 100; i++) {
        value[i] = uint8_t(i);
    }
    uint8_t *key = value;
    int len = 100;
    uint32_t seed = 5;
    uint64_t out[2];
    hash_x86_128(key,len,seed,out);

    len = 16;
    hash_x86_128(key,len,seed,out);

    len = 15;
    hash_x86_128(key,len,seed,out);

    len = 14;
    hash_x86_128(key,len,seed,out);

    len = 13;
    hash_x86_128(key,len,seed,out);

    len = 12;
    hash_x86_128(key,len,seed,out);

    len = 11;
    hash_x86_128(key,len,seed,out);

    len = 10;
    hash_x86_128(key,len,seed,out);

    len = 9;
    hash_x86_128(key,len,seed,out);

    len = 8;
    hash_x86_128(key,len,seed,out);

    len = 7;
    hash_x86_128(key,len,seed,out);

    len = 6;
    hash_x86_128(key,len,seed,out);

    len = 5;
    hash_x86_128(key,len,seed,out);
}

TEST(UT_Hash, test_hash_x64_128_01)
{
    uint8_t value[10] {};
    for (int i = 0; i < 10; i++) {
        value[i] = uint8_t(i);
    }
    uint8_t *key = value;
    int len = 4;
    uint32_t seed = 5;
    uint64_t out[2];
    hash_x64_128(key,len,seed,out);
}

TEST(UT_Hash, test_init_seed_01)
{
    init_seed();
}