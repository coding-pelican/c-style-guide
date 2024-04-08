# C Style Guide

Still a work in progress.

## Layout & Order of Groupings

`Public`  ::= `extern`

`Private` ::= `static`

### Header files

The following groupings should appear in all C header files in the following order:

```txt
1.  Heading comment
  2.  Doxygen file prologue
  3.  Release statement and copyright

4-s.  Header file include guard (opening)
5-s.  C language link (opening)

  6.  Header file inclusions (when NEEDED instead of forward declarations)
  7.  Pre-processor definitions
  8.  Forward declarations (when NEEDED in this header file)

  9.  Public types (definitions: const, enum, struct, ...)
  10. Public data (declarations: global, extern, static with extern)
  11. Inline functions (definitions)
  12. Public function prototypes (declarations)

5-e.  C language link (closing)
4-e.  Header file include guard (closing)
```

example.h:

```c
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
#ifdef __cplusplus
extern "C" {
#endif // __cplusplus

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
void Bar_Destroy(Bar** outBar);

// 5-e. C language link (closing)
#ifdef __cplusplus
}
#endif // __cplusplus

// 4-e. Header file include guard (closing)
#endif // !EXAMPLE_H
```

### Source files

The following groupings should appear in all C source files in the following order:

```txt
1.  Heading comment
  2.  Doxygen file prologue
  3.  Release statement and copyright

4.  Header file inclusions (only those that are NECESSARY)
5.  Pre-processor definitions

6.  Private types (definitions)
7.  Private data (definitions)
8.  Private function prototypes (declarations)

9.  Public data (definitions)
10. Public functions (definitions)
11. Private functions (definitions)
```

example.c

```c
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

void Bar_Destroy(Bar** outBar) {
    ASSERT(outBar);
    ASSERT(*outBar);
    free(*outBar);
    *outBar = NULL;

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
  // ...
}
```

## References

[Syque's C Style/CHAPTER 7 : File Layout](http://syque.com/cstyle/ch7.3.htm)

[NuttX documentation's C Coding Standard/File Organization](https://nuttx.apache.org/docs/latest/contributing/coding_style.html#file-organization)

[Axom documentation's Coding Guidelines/4 Header File Organization](https://axom.readthedocs.io/en/develop/docs/sphinx/coding_guide/sec04_header_org.html)
