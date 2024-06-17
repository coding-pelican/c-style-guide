// clang-format off

/**
 * @file example.h
 * @author {YourName} ({your.email_address@where.com})
 *
// 2. Doxygen file prologue
 * @brief Example header file.
 * @details This header file shows an example of the layout and grouping order.
 *
// 3. Release statement and copyright
 * @version {major}.{minor}.{path}{-{pre.release}(optional)}
 * @date YYYY-MM-DD
 *
 * @copyright Copyright {YYYY}. {Your{Name|Company}} All rights reserved.
            | Released under the {YourLicense a}. See LICENSE file for details.
 */

// 4-s. Header file include guard (opening)
#ifndef EXAMPLE_H
#define EXAMPLE_H

// 5-s. C language link (opening)
#if defined(__cplusplus)
extern "C" {
#endif // defined(__cplusplus)

// 6. Header file inclusions (when NEEDED instead of forward declarations)
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "foo.h"

// 7. Pre-processor definitions
#define EXAMPLE_MAX_SIZE 100

// 8. Forward declarations (when NEEDED in this header file)
typedef struct Foo Foo;

// 9. Public types (definitions)
enum eExampleType {
    eExampleType_None = -1,
    eExampleType_Foo  =  0,
    eExampleType_Bar,
    eExampleType_Baz,
    kExampleType_Count
};
typedef int32_t ExampleType;

typedef struct Point Point;
struct Point {
    int x;
    int y;
};

typedef struct Bar Bar;
struct Bar {
    ExampleType type;
    Foo foo;
    Point p;
};

static char const* const kBarTypeName = "Bar";
static int         const kBarInitX = 0;
static int         const kBarInitY = 0;
static Point       const kBarInitPoint = {kBarInitX, kBarInitY};

// 10. Public data (declarations)
extern int gBarCreatedCount;
extern int gBarDestroyedCount;

// 11. Inline functions (definitions)
static inline Point Point_AddPoint(Point p, Point q) {
    return (Point){
        .x = p.x + q.x,
        .y = p.y + q.y
    };
}

static inline Point Point_Scale(Point p, int s) {
    return (Point){
        .x = p.x * s,
        .y = p.y * s
    };
}

// 12. Public function prototypes (declarations)
bool ProcessData(uint8_t const* refData, size_t size);
Bar* Bar_Create();
Bar* Bar_Initialize(Bar* outBar, Foo foo, Point p);
void Bar_Destroy(Bar** outBarPtr);

// 5-e. C language link (closing)
#if defined(__cplusplus)
}
#endif // defined(__cplusplus)

// 4-e. Header file include guard (closing)
#endif // !EXAMPLE_H

// clang-format on
