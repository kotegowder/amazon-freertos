/*
 * Copyright (C) 2018 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 * Copyright (c) 2019 Arm Limited. All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 */

/**
 * @file iot_test_pkcs11_psa.c
 * @brief Functions dedicated for the PKCS11 test in the PSA based implementation case.
 */

/* C runtime includes. */
#include <stdint.h>
#include <string.h>

/**
 * This function is not used in the PSA based PKCS#11 API implementation.
 * It is only used in the PKCS#11 test.
 */
int mbedtls_hardware_poll( void *data,
						   unsigned char *output, size_t len, size_t *olen )
{
	/* FIX ME
	 * This need to generate a random number by hardware.
	 */
	( void ) (data);
	( void ) (len);

	static uint32_t random_number = 0;

	random_number += 8;
	memcpy(output, &random_number, sizeof(uint32_t));
	*olen = sizeof(uint32_t);

	return 0;
}