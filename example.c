// clang-format off
//
// 1. Heading comment
/**
 * @file example.c
 * @author {YourName} ({your.email_address@where.com})
 *
// 2. Doxygen file prologue
 * @brief Example source file.
 * @details This source file provides implementations for functions declared in example.h.
 *
// 3. Release statement and copyright
 * @version {major}.{minor}.{path}{-{pre.release}(optional)}
 * @date YYYY-MM-DD
 *
 * @copyright Copyright {YYYY} {Your{Name|Company}}. All rights reserved.
            | Released under the {YourLicense a}. See LICENSE file for details.
 */

// 4. Header file inclusions (only those that are NECESSARY)
#include "example.h"
#include <stdbool.h> // Include standard boolean type
#include <stdio.h>   // Include standard I/O library for printf
#include <stdlib.h> // Include standard library for malloc

// 5. Pre-processor definitions
#define EXAMPLE_ADD(_x, _y) ((_x) + (_y))
#define EXAMPLE_SUB(_x, _y) ((_x) + (_y))
#define EXAMPLE_MAX(_a, _b) (((_a) < (_b)) ? (_b) : (_a))
#define EXAMPLE_MIN(_a, _b) (((_a) > (_b)) ? (_b) : (_a))

#define EXAMPLE_DEBUG
#ifdef EXAMPLE_DEBUG
#  define ASSERT(_condition)                               \
    do {                                                   \
        if (!(_condition)) {                               \
            (void)fprintf(                                 \
                stderr, "%s:%d: Assertion '%s' failed.\n", \
                __FILE__, __LINE__, #_condition            \
            );                                             \
            __builtin_trap();                              \
        }                                                  \
    } while(0)
#else
#  define ASSERT(condition) ((void)0)
#endif // EXAMPLE_DEBUG

#define EXAMPLE_SWAP(_T, _a, _b) \
    do {                         \
        _T __t = (_a);           \
        (_a)   = (_b);           \
        (_b)   = __t;            \
    } while (0)

#define EXAMPLE_DO_ASSIGN(_a, _b) do { (_a) = (_b); } while (0)

#define EXAMPLE_TYPE_IS_FOO(_obj) ((_obj).type == eExampleType_Foo)

// 6. Private types (definitions)
typedef struct Baz Baz;
struct Baz {
    ExampleType type;
    Bar         bar;
    float       value;
};

// 7. Private data (definitions)
static int sCurrentBarCount = 0;

// 8. Private function prototypes (declarations)
static void TestPoint();

// 9. Public Data (definitions)
int gBarCreatedCount   = 0; // Initialize global variable
int gBarDestroyedCount = 0; // Initialize global variable

// 10. Public functions (definitions)
bool ProcessData(uint8_t const* refData, size_t size) {
    (void)(refData);
    (void)(size);
    // Implementation of ProcessData function
    return true;
}

Bar* Bar_Create() {
    gBarCreatedCount++;
    sCurrentBarCount++;
    return (Bar*)malloc(sizeof(Bar));
}

Bar* Bar_Initialize(Bar* outBar, Foo foo, Point p) {
    ASSERT(outBar);
    ASSERT(EXAMPLE_TYPE_IS_FOO(foo));

    outBar->type = eExampleType_Bar;
    outBar->foo  = foo;
    outBar->p    = p;

    return outBar;
}

void Bar_Destroy(Bar** outBarPtr) {
    ASSERT(outBarPtr);
    ASSERT(*outBarPtr);
    free(*outBarPtr);
    *outBarPtr = NULL;

    gBarDestroyedCount++;
    sCurrentBarCount--;
}

int main() {
    TestPoint();

    Bar* bar = Bar_Initialize(Bar_Create(), (Foo){.type = eExampleType_Foo, .value = 42}, kBarInitPoint);
    ASSERT(bar);
    ASSERT(bar->type == eExampleType_Bar);
    ASSERT(gBarCreatedCount == 1);
    ASSERT(gBarDestroyedCount == 0);
    ASSERT(sCurrentBarCount == 1);

    Bar_Destroy(&bar);
    if (!bar) {
        printf("Bar object was successfully destroyed.\n");
    }
    ASSERT(gBarCreatedCount == 1);
    ASSERT(gBarDestroyedCount == 1);
    ASSERT(sCurrentBarCount == 0);

    return 0;
}

// 11. Private functions (definitions)
static void TestPoint() {
    // Point AddPoint
    {
        Point p = { .x = 1, .y = 2 };
        Point q = { .x = 3, .y = 4 };
        Point result = Point_AddPoint(p, q);
        ASSERT(4 == result.x);
        ASSERT(6 == result.y);
    }

    // Point AddPoint ZeroPoints
    {
        Point p = { .x = 0, .y = 0 };
        Point q = { .x = 0, .y = 0 };
        Point result = Point_AddPoint(p, q);
        ASSERT(0 == result.x);
        ASSERT(0 == result.y);
    }

    // Point AddPoint NegativePoints
    {
        Point p = { .x = -1, .y = -2 };
        Point q = { .x = -3, .y = -4 };
        Point result = Point_AddPoint(p, q);
        ASSERT(-4 == result.x);
        ASSERT(-6 == result.y);
    }

    // Point Scale
    {
        Point p = { .x = 2, .y = 3 };
        int s = 2;
        Point result = Point_Scale(p, s);
        ASSERT(result.x == 4);
        ASSERT(result.y == 6);
    }

    // Point Scale ZeroScale
    {
        Point p = { .x = 2, .y = 3 };
        int s = 0;
        Point result = Point_Scale(p, s);
        ASSERT(result.x == 0);
        ASSERT(result.y == 0);
    }

    // Point Scale NegativeScale
    {
        Point p = { .x = 2, .y = 3 };
        int s = -2;
        Point result = Point_Scale(p, s);
        ASSERT(result.x == -4);
        ASSERT(result.y == -6);
    }
}

// clang-format on
