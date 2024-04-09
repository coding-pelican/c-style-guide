/**
 * @file foo.h
 * @author Gyeongtae Kim(dev-dasae) (codingpelican@gmail.com)
 *
 * @brief Foo struct definition.
 * @details This header file defines the Foo struct and related functions.
 *
 * @version 0.1
 * @date 2024-04-08
 *
 * @copyright Released under the MIT License. See LICENSE file for details.
 */


#ifndef FOO_H
#define FOO_H

#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

// #region Public_Types
typedef struct Foo Foo;
struct Foo {
    int type;
    int value;
};
// #endregion Public_Types

#ifdef __cplusplus
}
#endif // __cplusplus

#endif // !FOO_H
