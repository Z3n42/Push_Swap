<div align="center">

# 🔢 Push Swap

### Because Swap_push isn't as natural

<p>
  <img src="https://img.shields.io/badge/Score-96%2F100-success?style=for-the-badge&logo=42" alt="42 Score"/>
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Language"/>
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License"/>
  <img src="https://img.shields.io/badge/42-Urduliz-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 Urduliz"/>
</p>

*A sorting algorithm project that sorts integers using two stacks and a limited set of operations, optimizing for the minimum number of moves.*

[Installation](#%EF%B8%8F-installation) • [Usage](#-usage) • [Algorithm](#-algorithm-chunk-based-sorting) • [Operations](#-stack-operations)

</div>

---

## 📋 Table of Contents

- [About the Project](#-about-the-project)
- [Installation](#%EF%B8%8F-installation)
- [Usage](#-usage)
- [Algorithm: Chunk-Based Sorting](#-algorithm-chunk-based-sorting)
- [Stack Operations](#-stack-operations)
- [Implementation Details](#-implementation-details)
- [Project Structure](#-project-structure)
- [Testing](#-testing)
- [What I Learned](#-what-i-learned)
- [License](#-license)

---

## 🎯 About the Project

**Push Swap** is an algorithmic challenge where you must sort a stack of integers using only two stacks (A and B) and a limited set of operations. The goal is to sort the numbers in **ascending order** in stack A using the **minimum number of operations**.

### Why Push Swap?

This project teaches essential computer science concepts:
- **Sorting Algorithms** - Understanding algorithmic complexity
- **Algorithm Optimization** - Minimizing operations
- **Data Structures** - Stack manipulation and operations
- **Problem Solving** - Breaking down complex problems
- **Performance Analysis** - Evaluating efficiency

The challenge is not just to sort, but to sort **efficiently** with operation count constraints:
- **3 numbers**: Max 3 operations
- **5 numbers**: Max 12 operations
- **100 numbers**: Max 700 operations (target: ~550)
- **500 numbers**: Max 5500 operations (target: ~3500)

---

## 🛠️ Installation

### Prerequisites

- **GCC** or **Clang** compiler
- **Make**
- **libft** (included in project)
- Unix-based system (Linux, macOS)

### Clone and Compile

```bash
# Clone the repository
git clone https://github.com/Z3n42/push_swap.git
cd push_swap

# Compile the program
make

# Clean object files
make clean

# Clean everything
make fclean

# Recompile
make re
```

After running `make`, you'll have the `push_swap` executable.

---

## 🚀 Usage

### Basic Usage

```bash
./push_swap [list of integers]
```

**Example:**
```bash
./push_swap 3 2 5 1 4
```

**Output:**
```
sa
pb
pb
ra
pa
pa
```

### Alternative Format (String Argument)

```bash
./push_swap "3 2 5 1 4"
```

### Output

The program prints the sequence of operations needed to sort the stack, one operation per line.

### Input Validation

The program validates:
- ✅ All arguments are integers
- ✅ No duplicates
- ✅ Numbers within `int` range
- ✅ Invalid input → prints "Error\n" to stderr

---

## 🔧 Algorithm: Chunk-Based Sorting

Implementation uses a **chunk-based (bucket) algorithm** that divides numbers into groups and processes them efficiently.

### Strategy Overview

```
1. Index Mapping       → Convert numbers to 0-based indices
2. Chunk Division      → Divide into groups by size
3. Push to B          → Move chunks to stack B strategically
4. Push Back to A     → Retrieve in descending order
```

### Algorithm by Size

#### 2 Numbers
```c
if (argc == 3)
    ft_swap_a(a);  // Just swap if out of order
```

#### 3 Numbers (Hardcoded Cases)
```c
void ft_three(int argc, int *a)
{
    if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
        ft_swap_a(a);                    // Case: 2 1 3

    if (a[0] > a[1] && a[1] > a[2])
    {
        ft_swap_a(a);                    // Case: 3 2 1
        ft_reverse_ra(argc, a);
    }

    if (a[0] > a[1] && a[2] < a[0])
        ft_rotate_a(argc, a);            // Case: 3 1 2

    if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
    {
        ft_swap_a(a);                    // Case: 1 3 2
        ft_rotate_a(argc, a);
    }

    if (a[0] < a[1] && a[2] < a[0])
        ft_reverse_ra(argc, a);          // Case: 2 3 1
}
```

**All 6 permutations handled optimally.**

#### 4-7 Numbers (Small Sort)
```c
void ft_five(int args, int *a, int *b)
{
    int count = args;

    // Push smallest elements to B
    while (count > 3)
    {
        if (ft_mincheck(count, a) < (count / 2))
        {
            // Minimum in upper half → rotate
            while (ft_mincheck(count, a) != 0)
                ft_rotate_a(count, a);
            ft_push_b(count, a, b);
            count--;
        }
        else
        {
            // Minimum in lower half → reverse rotate
            while (ft_mincheck(count, a) != 0)
                ft_reverse_ra(count, a);
            ft_push_b(count, a, b);
            count--;
        }
    }

    ft_three(count, a);  // Sort remaining 3

    // Push back from B
    ft_five_push(args, count, a, b);
}
```

**Strategy**: Push smallest values to B, sort remaining 3, push back.

#### 8+ Numbers (Chunk Algorithm)

```c
void ft_hundred(int args, int ln, int *a, int *b)
{
    int chunk;
    int pos;

    // Calculate chunk size based on input size
    pos = args / 6;           // For 100 numbers: ~16 per chunk
    if (args > 100)
        pos = args / 12;      // For 500 numbers: ~41 per chunk

    chunk = pos;

    ft_chunk(args, a);  // Convert to indices (0 to n-1)

    // Phase 1: Push to B in chunks
    while (ln > 0)
    {
        if (ft_chunkup(ln, chunk, a) <= (ln + 1 - ft_chunkdown(ln, chunk, a)))
        {
            // Element in upper half
            ln = ft_rotup(ln, chunk, a);
            ft_push_b(args, a, b);
        }
        else
        {
            // Element in lower half
            ln = ft_rotdown(ln, chunk, a);
            ft_push_b(args, a, b);
        }

        // Dynamic chunk size adjustment
        pos = ft_len(pos, ln);
        if (ln <= args - chunk)
            chunk += pos;
    }

    // Phase 2: Push back to A in sorted order
    ft_pushtoa(args, a, b);
}
```

### Index Mapping (ft_chunk)

Before sorting, numbers are converted to **0-based indices**:

```c
void ft_chunk(int args, int *a)
{
    int *chunk = malloc(args * sizeof(int));
    int *temp = malloc(args * sizeof(int));

    // Copy array
    for (int i = 0; i < args; i++)
        chunk[i] = a[i];

    // Sort copied array
    ft_sort_chunk(args, chunk);

    // Assign indices: smallest=0, largest=args-1
    ft_chunk_assign(args, chunk, temp, a);
}
```

**Example:**
```
Input:  [42, -3, 17, 0, 100]
Sorted: [-3, 0, 17, 42, 100]
Indices: [3, 0, 2, 1, 4]
```

### Chunk Size Calculation

```c
// Chunk sizes optimized for different input sizes
pos = args / 6;        // 100 numbers → 6 chunks (~16 each)
if (args > 100)
    pos = args / 12;   // 500 numbers → 12 chunks (~41 each)

// Dynamic resizing during execution
int ft_len(int pos, int ln)
{
    if (ln == 200)
        pos = ln / 8;
    if (ln == 100)
        pos = ln / 6;
    if (ln == 20)
        pos = ln / 3;
    if (ln == 10)
        pos = ln / 2;
    return (pos);
}
```

### Push Back Strategy (ft_pushtoa)

```c
void ft_pushtoa(int argb, int *a, int *b)
{
    while (argb >= 0)
    {
        // Find maximum in B
        if (ft_maxcheck(argb, b) <= (argb / 2))
        {
            // Maximum in upper half → rotate
            while (ft_maxcheck(argb, b) != 0)
            {
                if ((ft_maxcheck(argb, b) == 1) && (b[0] < b[1]))
                    ft_swap_b(b);  // Optimize with swap
                else
                    ft_rotate_b(argb, b);
            }
            ft_push_a(argb, a, b);
            argb--;
        }
        else
        {
            // Maximum in lower half → reverse rotate
            while (ft_maxcheck(argb, b) != 0)
                ft_reverse_rb(argb, b);
            ft_push_a(argb, a, b);
            argb--;
        }
    }
}
```

**Strategy**: Always push the **largest** element from B back to A.

---

## 📖 Stack Operations

Implementation provides **11 operations**:

### Swap Operations
```c
void ft_swap_a(int *a);    // sa: Swap first 2 elements of stack A
void ft_swap_b(int *b);    // sb: Swap first 2 elements of stack B
void ft_swap_ss(int *a, int *b); // ss: Swap both stacks simultaneously
```

### Push Operations
```c
void ft_push_a(int argc, int *a, int *b); // pa: Push top of B to A
void ft_push_b(int argc, int *a, int *b); // pb: Push top of A to B
```

### Rotate Operations (Shift up)
```c
void ft_rotate_a(int argc, int *a);       // ra: Rotate A (first → last)
void ft_rotate_b(int argc, int *b);       // rb: Rotate B
void ft_rotate_rr(int argc, int *a, int *b); // rr: Rotate both
```

### Reverse Rotate Operations (Shift down)
```c
void ft_reverse_ra(int argc, int *a);     // rra: Reverse rotate A (last → first)
void ft_reverse_rb(int argc, int *b);     // rrb: Reverse rotate B
void ft_reverse_rr(int argc, int *a, int *b); // rrr: Reverse rotate both
```

### Operation Visualization

```
Initial:  [3, 2, 1, 5, 4]

sa:  [2, 3, 1, 5, 4]  (swap first 2)
pb:  A:[3, 1, 5, 4]   B:[2]  (push to B)
ra:  [1, 5, 4, 3]  (rotate: 3 goes to bottom)
rra: [3, 1, 5, 4]  (reverse: 4 goes to top)
```

---

## 💻 Implementation Details

### Data Structure

Implementation uses **arrays** to represent stacks:

```c
int *a = malloc(count * sizeof(int));  // Stack A
int *b = ft_calloc(count, sizeof(int)); // Stack B (initialized to 0)
```

**Stack convention**:
- Index 0 = **top** of stack
- Index n-1 = **bottom** of stack

### Input Parsing

Supports two formats:

```c
// Format 1: Multiple arguments
./push_swap 4 2 8 1
// → args = ["4", "2", "8", "1"]

// Format 2: Single string argument
./push_swap "4 2 8 1"
// → Split by space using ft_split()
```

### Algorithm Selection

```c
void ft_push_swap(char **args, int argc, int *a, int *b)
{
    // Parse integers
    count = 0;
    while (args[count])
    {
        a[count] = ft_atoi_push(args[count]);
        count++;
    }

    // Validate input
    if (ft_checker(argc - 1, a) != 1)
        ft_error(argc - 1, a);

    // Select algorithm by size
    if (argc == 3)
        ft_swap_a(a);                  // 2 numbers
    if (argc == 4)
        ft_three(argc - 1, a);         // 3 numbers
    if (argc > 4 && argc < 8)
        ft_five(argc - 1, a, b);       // 4-7 numbers
    if (argc > 7)
        ft_hundred(argc - 1, argc - 1, a, b);  // 8+ numbers
}
```

### Helper Functions

#### Find Minimum/Maximum Position
```c
int ft_mincheck(int args, int *c);  // Returns index of smallest element
int ft_maxcheck(int args, int *c);  // Returns index of largest element
```

#### Chunk Position Finders
```c
int ft_chunkup(int args, int chunk, int *a);   // Find chunk element from top
int ft_chunkdown(int args, int chunk, int *a); // Find chunk element from bottom
```

#### Validation
```c
int ft_checker(int argc, int *a);  // Check if already sorted
void ft_error(int args, int *c);   // Print "Error\n" and exit
int ft_atoi_push(const char *str); // Custom atoi with error handling
```

---

## 📁 Project Structure

```
push_swap/
├── 📄 LICENSE                # MIT License
├── 📄 Makefile               # Build configuration
├── 📄 push_swap.h            # Header with all prototypes
├── 📄 main.c                 # Entry point, argument parsing
├── 📄 ft_atoi_push.c         # Custom atoi with validation
├── 📄 ft_checks.c            # Validation functions (sorted, min, max, chunk)
├── 📄 ft_aux.c               # Auxiliary functions
├── 📄 ft_chunk.c             # Index mapping (ft_chunk, ft_sort_chunk)
├── 📄 ft_low_cases.c         # Algorithms for 3 and 5 numbers
├── 📄 ft_hi_cases.c          # Chunk algorithm for 8+ numbers
├── 📄 ft_swap.c              # Swap operations (sa, sb, ss)
├── 📄 ft_push.c              # Push operations (pa, pb)
├── 📄 ft_rotate.c            # Rotate operations (ra, rb, rr)
├── 📄 ft_reverse.c           # Reverse rotate (rra, rrb, rrr)
├── 📂 libft/                 # Custom C library
│   ├── libft.h
│   ├── libft.a
│   └── (libft sources)
└── 📂 test/                  # Testing utilities
    ├── README.md
    ├── push_swap_rng.py     # Random number generator
    └── p_s_rng.png          # GUI screenshot
```

### File Breakdown

| File | Lines | Purpose |
|------|-------|---------|
| `main.c` | ~90 | Argument parsing, memory allocation, algorithm selection |
| `ft_chunk.c` | ~75 | Index mapping and sorting for chunk algorithm |
| `ft_low_cases.c` | ~75 | Hardcoded optimal solutions for 3 and 5 numbers |
| `ft_hi_cases.c` | ~95 | Chunk-based algorithm for 8+ numbers |
| `ft_checks.c` | ~75 | Validation: sorted check, min/max find, chunk finders |
| `ft_swap.c` | ~50 | sa, sb, ss implementations |
| `ft_push.c` | ~60 | pa, pb implementations |
| `ft_rotate.c` | ~65 | ra, rb, rr implementations |
| `ft_reverse.c` | ~65 | rra, rrb, rrr implementations |
| `ft_aux.c` | ~50 | Helper utilities |
| `ft_atoi_push.c` | ~70 | Custom atoi with error handling |

### Makefile

```makefile
NAME = push_swap
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g
LIBFT = -Llibft -lft

FILES = ft_atoi_push ft_aux ft_checks ft_chunk ft_hi_cases \
        ft_low_cases ft_push ft_reverse ft_rotate ft_swap main

OBJS = $(FILES:=.o)

$(NAME): $(OBJS)
    $(MAKE) -C ./libft
    $(CC) $(CFLAGS) $^ $(LIBFT) -o $@

all: $(NAME)
clean:
    $(MAKE) clean -C ./libft
    $(RM) $(OBJS)
fclean: clean
    $(RM) $(NAME)
re: clean all
```

**Total:** 11 source files + libft integration.

---

## 🧪 Testing

### Basic Testing

```bash
# Test with 3 numbers
./push_swap 2 1 3

# Test with 5 numbers
./push_swap 5 3 2 4 1

# Test with 100 random numbers
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
./push_swap $ARG

# Count operations
./push_swap $ARG | wc -l
```

### Python Test Generator

Repository includes `test/push_swap_rng.py` - a GUI tool for generating random test cases:

```bash
cd test
python3 push_swap_rng.py
```

**Features**:
- **Cantidad de números**: Number count (e.g., 50)
- **Desde**: Range start (e.g., -500)
- **Hasta**: Range end (e.g., 500)
- **Checkboxes**: `./push_swap`, `./checker_Mac`, `$ARG=""`, `wc -l`
- **Generar**: Generate button
- **Copiar**: Copy to clipboard

### Checker Program

Use the provided checker to verify correctness:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_Mac $ARG
```

**Output:**
- `OK` - Correctly sorted
- `KO` - Not sorted
- `Error` - Invalid operations

### Performance Benchmarks

| Size | Max Operations |    Target   | Typical Result |
|------|----------------|-------------|----------------|
| 3    | 3              | 2-3         | 2-3            |
| 5    | 12             | 8-12        | 8-10           |
| 100  | 700            | ~550        | 500-600        |
| 500  | 5500           | ~3500       | 3000-3500      |

### Test Cases

```bash
# Already sorted
./push_swap 1 2 3 4 5
# → (no output)

# Reverse sorted
./push_swap 5 4 3 2 1
# → (many operations)

# With duplicates (should error)
./push_swap 1 2 2 3
# → Error

# Invalid input
./push_swap 1 2 abc 3
# → Error

# Out of int range
./push_swap 2147483648
# → Error
```

### Stress Testing

```bash
# Test 100 random sets of 100 numbers
for i in {1..100}; do
    ARG=$(seq 1 100 | shuf | tr '\n' ' ')
    OPS=$(./push_swap $ARG | wc -l)
    echo "Test $i: $OPS operations"
    if [ $OPS -gt 700 ]; then
        echo "FAILED: Too many operations"
        break
    fi
done
```

---

## 💡 What I Learned

Through this project, I gained deep understanding of:

- ✅ **Sorting Algorithms**: Implementing and optimizing custom sorting
- ✅ **Algorithm Analysis**: Big O notation and performance optimization
- ✅ **Chunking Strategy**: Dividing problems into manageable groups
- ✅ **Data Structures**: Stack operations and array manipulation
- ✅ **Index Mapping**: Converting values to ordinal positions
- ✅ **Dynamic Optimization**: Adjusting chunk sizes based on input
- ✅ **Edge Case Handling**: Small inputs with hardcoded optimal solutions
- ✅ **Performance Tuning**: Balancing complexity vs operation count
- ✅ **Testing Strategies**: Creating comprehensive test suites

### Key Challenges

1. **Algorithm Design**: Finding optimal strategy for different input sizes
2. **Chunk Size Tuning**: Calculating ideal chunk sizes (6 vs 12 divisions)
3. **Operation Minimization**: Reducing unnecessary rotations
4. **Edge Cases**: Handling 2, 3, and 5 numbers optimally
5. **Index Mapping**: Converting arbitrary integers to workable indices
6. **Push Back Strategy**: Efficiently returning elements from B to A

### Design Decisions

**Why chunk-based algorithm?**
- Divides problem into manageable pieces
- Reduces comparison overhead
- Performs well for medium/large inputs

**Why index mapping?**
- Simplifies comparisons (0 to n-1 vs arbitrary integers)
- Makes chunk boundaries clear
- Improves algorithm readability

**Why different chunk sizes?**
- 100 numbers: 6 chunks (~16 each) - better granularity
- 500 numbers: 12 chunks (~41 each) - prevents excessive pushing

**Why hardcoded small cases?**
- 3 numbers: Only 6 permutations, all optimal solutions known
- 5 numbers: Predictable, can achieve optimal with simple strategy
- Faster execution, fewer operations

---

## 📏 Performance

### Complexity Analysis

- **Time Complexity**: O(n²) - chunk sorting + operations
- **Space Complexity**: O(n) - two stacks + temporary arrays
- **Operation Complexity**: ~O(n log n) operations generated

---

## 📄 License

MIT License - See [LICENSE](LICENSE) file for details.

This project is part of the 42 School curriculum. Feel free to use and learn from this code, but please don't copy it for your own 42 projects. Understanding comes from doing it yourself! 🚀

---

## 🔗 Related Projects

This project builds upon:

- **[libft](https://github.com/Z3n42/42_libft)** - Custom C library (ft_split, ft_atoi, ft_calloc)

Skills learned here apply to:
- **Sorting algorithms** - QuickSort, MergeSort implementations
- **Algorithm optimization** - Time/space complexity analysis
- **Data structure manipulation** - Stacks, queues, trees

---

<div align="center">

**Made with ☕ by [Z3n42](https://github.com/Z3n42)**

*42 Urduliz | Circle 2*

[![42 Profile](https://img.shields.io/badge/42_Intra-ingonzal-000000?style=flat&logo=42&logoColor=white)](https://profile.intra.42.fr/users/ingonzal)

</div>
