# Modern C and C++ Coding Convention

Written for projects Dasae Console Engine and Dasae Headers

## Table of Contents

- [Modern C and C++ Coding Convention](#modern-c-and-c-coding-convention)
  - [Table of Contents](#table-of-contents)
  - [File Naming Convention](#file-naming-convention)
  - [Naming Conventions](#naming-conventions)
    - [Common Naming Conventions](#common-naming-conventions)
    - [Common Naming Conventions Example](#common-naming-conventions-example)
  - [Object-Oriented(Modular) Programming](#object-orientedmodular-programming)
    - [C Modular Programming](#c-modular-programming)
      - [Example](#example)
    - [C++ Class Object-Oriented Programming](#c-class-object-oriented-programming)
  - [Header File Structure](#header-file-structure)
    - [Explanation](#explanation)
    - [Header File Structure Example](#header-file-structure-example)
  - [Data-Oriented Programming](#data-oriented-programming)
    - [Data Structures](#data-structures)
    - [Data Transformation Functions](#data-transformation-functions)
    - [Data-Oriented Macros](#data-oriented-macros)
    - [Data-Oriented Header File Structure](#data-oriented-header-file-structure)
    - [Data-Oriented Programming Example](#data-oriented-programming-example)
  - [Code Layout Guidelines](#code-layout-guidelines)
    - [1. Indentation](#1-indentation)
    - [2. Spacing](#2-spacing)
    - [3. Brace Placement](#3-brace-placement)
  - [Clang Format Configuration](#clang-format-configuration)

---

## File Naming Convention

- **Header Files (C):** `module{_submodule}.h`
- **Source Files (C):** `module{_submodule}.c`
- **Header Files (C++):** `Module.hpp`
- **Source Files (C++):** `Module.cpp`

## Naming Conventions

### Common Naming Conventions

- **Variables and Constants**
  - **Variables:** `camelCase`
  - **Global Variables:** `gCamelCase`
  - **Static Variables:** `sCamelCase`
  - **Constants:** `kCamelCase`

- **Functions and Methods**
  - **Constructor:** `Module_New` (in c)
  - **Destructor:** `Module_Delete` (in c)
  - **Methods:** `Module_MethodName` (without class(struct), Module == namespace in c)
  - **Global Functions:** `PascalCase`
  - **Structure Methods:** `PascalCase`

- **Enumerations and Enumerators**
  - **Enumerations:** `ePascalCase`
  - **Enumerators:** `ALL_CAPS`

- **Structures and Types**
  - **Classes/Objects:** `PascalCase`
  - **Class/Object Members:** `camelCase`

- **Macros**
  - **Macros:** `ALL_CAPS`
  - **Macro Functions:** `ALL_CAPS_WITH_UNDERSCORES`
  - **Macro Functions (Wrapper Macros):** `MODULE_InternalFunctionName`

- **Additional Cases**
  - **Local Variables:** `camelCase`
  - **Getter Methods:** `Module_getAttributeName`
  - **Setter Methods:** `Module_setAttributeName`
  - **Operator Overloads:** `operator+`, `operator-`, etc.
  - **Friend Functions:** `friendFunction`
  - **Templated Types:** `Template<Type>`
  - **Namespaces:** `namespace::Module`
  - **Typedefs:** `TypeAlias`
  - **Lambdas:** `[](parameters) { code }`

### Common Naming Conventions Example

```cpp
#include <iostream>

// Variables and Constants
int camelCaseVariable = 42;
double gCamelCaseGlobalVariable = 3.14;
static float sCamelCaseStaticVariable = 2.718;
const int kCamelCaseConstant = 100;

// Functions and Methods
class Module {
public:
    Module() {} // Constructor
    ~Module() {} // Destructor
    void MethodName() {} // Method
};

void PascalCaseGlobalFunction() {
    std::cout << "Global Function" << std::endl;
}

// Enumerations and Enumerators
enum ePascalCaseEnum {
    ENUM_VALUE_ONE,
    ENUM_VALUE_TWO
};

enum class eScopedEnum : int {
    SCOPED_ENUM_VALUE_ONE,
    SCOPED_ENUM_VALUE_TWO
};

// Structures and Types
class PascalCaseClass {
public:
    int camelCaseMemberVariable;
};

void _InternalFunctionName() {
    return;
}

// Macros
#define ALL_CAPS_MACRO (42)

#define MACRO_WITH_UNDERSCORES (3.14)

// Wrapper
#define MODULE_InternalFunctionName() _InternalFunctionName()

// Additional Cases
void friendFunction() {}

template <typename T>
class Template {
public:
    T data;
};

namespace MyNamespace {
    class Module {
    public:
        int getAttributeName() const { return attributeName_; }
        void setAttributeName(int attributeName) { attributeName_ = attributeName; }
    private:
        int attributeName_;
    };
}

int main() {
    // Variables and Constants
    camelCaseVariable = 84;
    gCamelCaseGlobalVariable = 6.28;
    sCamelCaseStaticVariable = 1.414;

    std::cout << "Constant Value: " << kCamelCaseConstant << std::endl;

    // Functions and Methods
    Module module;
    module.MethodName();
    PascalCaseGlobalFunction();

    // Enumerations and Enumerators
    ePascalCaseEnum enumValue = ENUM_VALUE_ONE;
    eScopedEnum scopedEnumValue = eScopedEnum::SCOPED_ENUM_VALUE_TWO;

    // Structures and Types
    PascalCaseClass pascalCaseObject;
    pascalCaseObject.camelCaseMemberVariable = 123;

    // Macros
    int macroResult = ALL_CAPS_MACRO + MACRO_WITH_UNDERSCORES;
    std::cout << "Macro Result: " << macroResult << std::endl;

    // Additional Cases
    friendFunction();

    Template<int> templatedObject;
    templatedObject.data = 42;

    MyNamespace::Module myModule;
    int attributeValue = myModule.getAttributeName();
    myModule.setAttributeName(56);

    return 0;
}
```

## Object-Oriented(Modular) Programming

### C Modular Programming

- **Module Naming:**
  - **Module Structure (Class/Object):** `Module`
  - **Module Members:** noun/adj (camelCase)
  - **Enums Type:** `Module[Noun/Adj]`
  - **Enumerations:** `eModule[Noun/Adj]`
  - **Enumerators:** `MODULE_ENUMERATOR`

- **Function Naming:**
  - **External Functions (public methods):**
    - `Module_[Verb/Adj]{Obj}`
  - **Internal Functions (private methods):**
    - `_{Module_}[Verb/Adj]{Obj}`

- **Variable Naming:**
  - **Global Variables (class/object properties):**
    - `gModule[Noun/Adj]`
  - **Static Variables (class/object properties):**
    - `sModule[Noun/Adj]`
  - **Module Getter Properties:**
    - `Module_getAttribute/GetAttribute`
  - **Module Setter Properties:**
    - `Module_setAttribute/SetAttribute`

- **Macro Functions**
  - **Module-Specific Macros:** `MODULE_SPECIFIC_MACRO`
  - **Global Macros for Module:** `GLOBAL_MODULE_MACRO`
  - **Wrapper Macros for Internal Function:** `MODULE_InternalFunctionName`

#### Example

```c
#include <stdio.h>

// Module structure
typedef struct Module Module;

// Function Declarations
// External Functions (public methods)
void Module_Initialize(Module* this);
int Module_getData(const Module* this);
void Module_setData(Module* this, int value);
// Internal Functions (private methods)
static void _InternalFunction(Module* this);

// Global/Static Variables (class/object properties)
int gModuleGlobalProperty = 0;
static float sModuleStaticProperty = 0.0;

// Macro Functions
#define MODULE_SPECIFIC_MACRO(x) ((x) * 2)
#define GLOBAL_MODULE_MACRO(y) ((y) + 10)

struct Module {
    int data;
};

// Enums
enum eModuleStatus {
    MODULE_STATUS_ENABLED,
    MODULE_STATUS_DISABLED
};

// Module Initialization
void Module_Initialize(Module* this) {
    this->data = 0;
}

// Module Getter Properties
int Module_getDataAttribute(const Module* this) {
    return obj->data;
}

// Module Setter Properties
void Module_setDataAttribute(Module* this, int value) {
    obj->data = value;
}

// Internal Function
static void _InternalFunction(Module* this) {
    // Perform internal logic here
    this->data += 10;
}


int main() {
    // Create an instance of the Module structure
    Module myModule;

    // Initialize the module
    Module_Initialize(&myModule);

    // Access and modify module data using getter and setter properties
    int dataValue = Module_getData(&myModule);
    printf("Initial Data Value: %d\n", dataValue);

    Module_setData(&myModule, 42);
    dataValue = Module_getData(&myModule);
    printf("Modified Data Value: %d\n", dataValue);

    // Call an internal function
    _InternalFunction(&myModule);

    // Access global and static properties
    gModuleGlobalProperty = 100;
    sModuleStaticProperty = 3.14;

    printf("Global Property: %d\n", gModuleGlobalProperty);
    printf("Static Property: %f\n", sModuleStaticProperty);

    // Use macro functions
    int result1 = MODULE_SPECIFIC_MACRO(5);
    int result2 = GLOBAL_MODULE_MACRO(20);

    printf("Macro Result 1: %d\n", result1);
    printf("Macro Result 2: %d\n", result2);

    return 0;
}

```

### C++ Class Object-Oriented Programming

- **Class Definition and Declaration**
  - **Class/Object Declaration:** `class ClassName;` (in header)
  - **Class/Object Definition:** `class ClassName { ... };` (in source)

- **Constructor and Destructor**
  - **Constructor Declaration:** `ClassName();`
  - **Constructor Definition:** `ClassName::ClassName() { ... }`
  - **Destructor Declaration:** `~ClassName();`
  - **Destructor Definition:** `ClassName::~ClassName() { ... }`

- **Member Functions**
  - **Public Member Functions:** `void MethodName();`
  - **Private Member Functions:** `private: void MethodName();`

- **Member Variables**
  - **Private Member Variables:** `private: DataType variableName_;`
  - **Public Member Variables (Avoid):** `public: DataType variableName;` (Use getter and setter methods instead)

- **Class Inheritance**
  - **Base Class (Parent):** `class BaseClass { ... };`
  - **Derived Class (Child):** `class DerivedClass : public BaseClass { ... };`

- **Polymorphism and Virtual Functions**
  - **Virtual Function Declaration:** `virtual void MethodName();`
  - **Override in Derived Class:** `void MethodName() override { ... }`

- **Encapsulation**
  - **Private Accessors (Getters):** `DataType getVariableName() const;`
  - **Private Mutators (Setters):** `void setVariableName(DataType value);`

- **Member Initialization List**
  - **Constructor Initialization List:** `ClassName::ClassName() : member1_(value1), member2_(value2) { ... }`

- **Namespaces**
  - **Namespace Declaration:** `namespace namespacename { ... }`

- **Operator Overloading**
  - **Operator Overload Declaration:** `ReturnType operator+(const ClassName& other) const;`
  - **Operator Overload Definition:** `ReturnType ClassName::operator+(const ClassName& other) const { ... }`

- **Friend Functions**
  - **Friend Function Declaration:** `friend ReturnType FriendFunction(const ClassName& obj);`
  - **Friend Function Definition:** `ReturnType FriendFunction(const ClassName& obj) { ... }`

- **Static Members**
  - **Static Member Variables:** `static DataType sVariableName;`
  - **Static Member Functions:** `static void sMethodName();`

- **Templates**
  - **Template Class Declaration:** `template <typename T> class TemplateClassName { ... };`
  - **Template Function Declaration:** `template <typename T> ReturnType TemplateFunction(T value);`

- **Macro Functions**
  - **Namespaced Macros:** `NAMESPACE_MACRO`
  - **Class-Specific Macros:** `CLASS_SPECIFIC_MACRO`

## Header File Structure

1. Include Guards
2. Includes
3. Type Definitions (typedefs, aliases)
4. Enums
5. Constants
6. Forward Declarations (classes, functions, templates)
7. Macros and Macro Function Wrappers
8. Structures
9. Function Declarations (methods and internal functions)
10. Inline Functions
11. Namespaces (C++)

### Explanation

- **Include Guards:** Ensure that the header file is included only once in a translation unit.
- **Includes:** Include necessary header files for dependencies.
- **Type Definitions:** Define type aliases and typedefs.
- **Enums:** Declare enumeration types.
- **Constants:** Declare constants or global constant variables.
- **Forward Declarations:** Declare classes, functions, or templates that are used but not defined in this header.
- **Macros and Macro Function Wrappers:** Define macros and Macro function wrappers that are used throughout the header or are meant to be included by other source files.
- **Structures:** Declare structs, classes, or objects.
- **Function Declarations:** Declare functions, methods, or constructors.
- **Inline Functions:** Define small, performance-critical functions that are suitable for inlining.
- **Namespaces (C++):** Define namespaces for encapsulation (C++ specific).

### Header File Structure Example

```c
#ifndef MODULE_H
#define MODULE_H

#include "dependency.h"

// Forward declarations
struct SomeStruct;
void SomeFunction(void);

// Constants
#define MAX_VALUE 100

// Macros and Macro Function Wrappers
#define MY_MACRO(x) ((x) * 2)
#define WRAP_SomeFunction() SomeFunction()

// Structures
struct ModuleStruct {
    int data;
};

...

#endif // MODULE_H
```

## Data-Oriented Programming

### Data Structures

- **Structure of Arrays (SoA):** `ModuleName_DataName` (e.g., `PhysicsSystem_Positions`, `RenderSystem_Colors`)
- **Array of Structures (AoS):** `ModuleNameData` (e.g., `PhysicsSystemData`, `RenderSystemData`)

### Data Transformation Functions

- **Data Initialization Functions:** `Module_InitializeData`
- **Data Update Functions:** `Module_UpdateData`
- **Data Query Functions:** `Module_QueryData`

### Data-Oriented Macros

- **Macro Functions for Data Operations:** `MODULE_DATA_OPERATION`

### Data-Oriented Header File Structure

1. Include Guards
2. Includes
3. Forward Declarations (classes, functions, templates)
4. Type Definitions (typedefs, aliases)
5. Constants
6. Data Structures (SoA and AoS)
7. Data Initialization Functions
8. Data Update Functions
9. Data Query Functions
10. Macros for Data Operations
11. Structures
12. Enums
13. Function Declarations (methods and internal functions)
14. Inline Functions
15. Namespaces (C++, if applicable)

### Data-Oriented Programming Example

```c
#ifndef MODULE_H
#define MODULE_H

#include "dependency.h"

struct Module_Positions {
    float x[1000];
    float y[1000];
};

struct ModuleData {
    int data[1000];
};

void Module_InitializeData(struct Module_Positions* positions);
void Module_UpdateData(struct ModuleData* data, float deltaTime);
void Module_QueryData(const struct ModuleData* data, int query);

#define MODULE_ADD_TO_DATA(data, value) ((data) += (value))
...

#endif // MODULE_H
```

## Code Layout Guidelines

### 1. Indentation

- **Consistency:** Regardless of whether you use spaces or tabs for indentation, it's crucial to be consistent throughout your codebase. Choose one method and stick to it.

Example using 4 spaces for indentation:

```c
void ExampleFunction() {
    if (condition) {
        // Indented code block
        DoSomething();
    }
}
```

### 2. Spacing

- **Operators:** When using operators such as `+`, `-`, `*`, or `/`, place spaces around them to enhance code readability.

Example:

```c
int result = a + b;
float ratio = c / d;
```

- **Commas:** In function arguments, variable declarations, and array initializations, include spaces after commas.

Example:

```c
void ExampleFunction(int arg1, int arg2, float arg3);
int array[] = {1, 2, 3, 4};
```

### 3. Brace Placement

- **Brace Styles:** Choose one of the common brace placement styles, such as the One True Brace Style (OTBS) or K&R style, and consistently apply it throughout your code.

  - OTBS:

    ```c
    void ExampleFunction() {
        if (condition) {
            DoSomething();
        } else {
          ...
        }
    }
    ```

  - K&R Style:

    ```c
    void ExampleFunction() {
        if (condition)
            DoSomething1();
        else
            DoSomething2();
    }
    ```

## Clang Format Configuration

The provided Clang format configuration is a set of rules that automate code formatting according to the specified guidelines. It enforces consistent code style by automatically adjusting your code. Let's break down some of the key rules from the configuration:

- **Indentation:** The `TabWidth` and `UseTab` settings control how tabs are used for indentation. In this configuration, `TabWidth` is set to 4 spaces, and `UseTab` is set to `Never`, which means spaces should be used for indentation.

- **Brace Placement:** The configuration defines where braces should be placed, such as after control statements and function definitions. For example, `BraceWrapping` settings control the placement of braces after control statements like `if`, `for`, and `while`.

- **Spacing:** Various settings control spacing around operators, braces, and other code elements. For instance, `SpaceBeforeAssignmentOperators` specifies whether there should be a space before assignment operators (`=`).

- **Line Length:** The `ColumnLimit` setting controls the maximum line length. Setting it to `0` means there's no maximum limit, but you can adjust it to your desired line length.

- **Other Stylistic Preferences:** The configuration covers a wide range of code formatting preferences, including how to format comments, template declarations, and more.

To apply this Clang format configuration to your code, you'll typically use the Clang Format tool, which can automatically format your code according to the rules defined in the configuration file.

By adhering to these code layout guidelines and using the provided Clang format configuration, your code will maintain a consistent and readable style, making it easier for both you and your team to understand and work with the codebase.
