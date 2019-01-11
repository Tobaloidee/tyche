/*
 * GNU General Public License Version 3.0, 29 June 2007
 * Header file of wide string.
 * Copyright (C) 2018  Sevak Amirkhanian
 * Email: amirkhanyan.sevak@gmail.com
 * For full notice please see https://github.com/amirkhaniansev/tyche/tree/master/LICENSE.
 */

#ifndef __WSTRING_T_H__
#define __WSTRING_T_H__

#include <stdbool.h>
#include <stddef.h>
#include <uchar.h>

#define WSTRING_IS_NULL             0x400
#define WSTRING_UCHAR_ARR_IS_NULL   0x401
#define WSTRING_INVALID_LENGTH      0x402

/** This is done to be able to change future implementations */
typedef char16_t uchar;

/** byte type **/
typedef unsigned char byte;

/* structure for holding Unicode strings */
typedef struct wstring_t_structure
{
	size_t _length;
    size_t _capacity;
    uchar* _buffer;
}wstring_t;

/**
 * wstring_create - creates an instance of wide string
 * Returns the instance if everything is OK, otherwise NULL.
 */
wstring_t* wstring_create();

/**
 * wstring_create_c - creates an instance of wide string from uchar array
 * @arr - arr
 * @lenght - length
 * Returns the instance if everything is OK, otherwise NULL.
 */
wstring_t* wstring_create_c(const uchar* arr, size_t length);

/**
 * wstring_create_copy - creates the copy of the string
 * @string - string to be copied
 */
wstring_t* wstring_create_copy(const wstring_t* string);

/**
 * wstring_compare - compares 2 side strings
 * @left - left string
 * @right - right string
 * Returns   0 if strings are equal
 *           1 if left > right
 *          -1 if left < right
 */
int wstring_compare(const wstring_t* left, const wstring_t* right);

/**
 * wstring_concat - concatenates 2 strings
 * @left - left string
 * @right - right string
 * Returns concatenation of 2 strings.
 */
wstring_t* wstring_concat(const wstring_t* left, const wstring_t* right);

/**
 * wstring_contains_uchar - checks if string contains the character
 * @string - string
 * @character - character
 * Returns true if string contains the character and false otherwise.
 */
bool wstring_contains_uchar(const wstring_t* string, const uchar character);

/**
 * wstring_contains_uchar - checks if string contains the character
 * @string - string
 * @substring - possible substring
 * Returns true if string contains the substring and false otherwise.
 */
bool wstring_contains_string(const wstring_t* string, const wstring_t* substring);


#endif
