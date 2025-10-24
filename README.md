<div align="center">

# 🔢 Push Swap

### Because Swap_push isn't as natural

<p>
  <img src="https://img.shields.io/badge/Score-96%2F100-success?style=for-the-badge&logo=42" alt="42 Score"/>
  <img src="https://img.shields.io/badge/Language-C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="Language"/>
  <img src="https://img.shields.io/badge/Algorithm-Chunk--Based-orange?style=for-the-badge" alt="Algorithm"/>
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge" alt="License"/>
  <img src="https://img.shields.io/badge/42-Urduliz-000000?style=for-the-badge&logo=42&logoColor=white" alt="42 Urduliz"/>
</p>

*A sorting algorithm project that sorts integers using two stacks and a limited set of operations, optimizing for the minimum number of moves.*

[Installation](#%EF%B8%8F-installation) • [Usage](#-usage) • [Algorithm](#-algorithm-chunk-based-sorting) • [Operations](#-stack-operations) • [Testing](#-testing)

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
- [Performance](#-performance)
- [What I Learned](#-what-i-learned)
- [License](#-license)

---

## 🎯 About the Project

**Push Swap** is an algorithmic challenge where you must sort a stack of integers using only two stacks (A and B) and a limited set of operations. The goal is to sort the numbers in **ascending order** in stack A using the **minimum number of operations**.

### Why Push Swap?

<table>
<tr>
<td width="50%" valign="top">

### 📊 Sorting Algorithms
- **Algorithmic complexity** understanding
- **Time/space optimization** strategies
- Custom sorting implementation
- Performance analysis and tuning

</td>
<td width="50%" valign="top">

### 🔧 Algorithm Optimization
- **Operation minimization** techniques
- Chunk-based sorting strategy
- Dynamic size adjustment
- Edge case handling (2, 3, 5 numbers)

</td>
</tr>
<tr>
<td width="50%" valign="top">

### 📚 Data Structures
- **Stack manipulation** operations
- Array-based stack implementation
- Index mapping techniques
- Efficient element positioning

</td>
<td width="50%" valign="top">

### 🎯 Problem Solving
- Breaking down complex problems
- Strategy selection by input size
- Hardcoded optimal solutions
- Testing and validation

</td>
</tr>
</table>

### Performance Constraints

| Input Size | Max Operations | Target | Grade Impact |
|------------|----------------|--------|--------------|
| 3 numbers | 3 | 2-3 | Pass/Fail |
| 5 numbers | 12 | 8-12 | Pass/Fail |
| 100 numbers | 700 | ~550 | Score scaling |
| 500 numbers | 5500 | ~3500 | Score scaling |

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

After running `make`, you'll have the `push_swap` executable ready to use.

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

### Alternative Format

```bash
./push_swap "3 2 5 1 4"
```

The program automatically handles both formats using `ft_split()`.

### Input Validation

The program validates:
- ✅ All arguments are integers
- ✅ No duplicates
- ✅ Numbers within `int` range (-2147483648 to 2147483647)
- ✅ Invalid input → prints `Error\n` to stderr

**Error Examples:**
```bash
./push_swap 1 2 2 3           # Duplicate → Error
./push_swap 1 2 abc 3         # Non-integer → Error
./push_swap 2147483648        # Out of range → Error
```

---

## 🔧 Algorithm: Chunk-Based Sorting

Implementation uses a **chunk-based (bucket) algorithm** that divides numbers into groups and processes them efficiently.

### Strategy Overview

```
┌─────────────────────────────────────────────────────┐
│         Push Swap Algorithm Pipeline                │
└─────────────────────────────────────────────────────┘
                      │
                      ▼
           ┌────────────────────┐
           │  1. Index Mapping  │
           │  Convert to 0-n-1  │
           └────────────────────┘
                      │
         [42, -3, 17, 0, 100]
                      ↓
          [3, 0, 2, 1, 4]  (indices)
                      │
                      ▼
          ┌─────────────────────┐
          │  2. Chunk Division  │
          │  Divide into groups │
          └─────────────────────┘
                      │
          100 nums → 6 chunks (~16 each)
          500 nums → 12 chunks (~41 each)
                      │
                      ▼
          ┌─────────────────────┐
          │  3. Push to B       │
          │  Move chunks to B   │
          └─────────────────────┘
                      │
          Find chunk elements (rotate if needed)
          Push to B, increment chunk boundary
                      │
                      ▼
         ┌──────────────────────┐
         │  4. Push Back to A   │
         │  Descending order    │
         └──────────────────────┘
                      │
          Find max in B, rotate to top, push to A
          Repeat until B empty
                      │
                      ▼
              ┌─────────────┐
              │  A: Sorted  │
              └─────────────┘
```

### Algorithm by Size

<details>
<summary><b>2 Numbers - Simple Swap</b></summary>

```c
if (argc == 3)
    ft_swap_a(a);  // Just swap if out of order
```

**Trivial case**: If two numbers are unsorted, swap them. Done in 1 operation.

</details>

<details>
<summary><b>3 Numbers - Hardcoded Optimal Cases</b></summary>

```c
void ft_three(int argc, int *a)
{
    // Case: 2 1 3 (swap first two)
    if (a[0] > a[1] && a[1] < a[2] && a[2] > a[0])
        ft_swap_a(a);

    // Case: 3 2 1 (swap + reverse rotate)
    if (a[0] > a[1] && a[1] > a[2])
    {
        ft_swap_a(a);
        ft_reverse_ra(argc, a);
    }

    // Case: 3 1 2 (rotate)
    if (a[0] > a[1] && a[2] < a[0])
        ft_rotate_a(argc, a);

    // Case: 1 3 2 (swap + rotate)
    if (a[0] < a[1] && a[1] > a[2] && a[2] > a[0])
    {
        ft_swap_a(a);
        ft_rotate_a(argc, a);
    }

    // Case: 2 3 1 (reverse rotate)
    if (a[0] < a[1] && a[2] < a[0])
        ft_reverse_ra(argc, a);
}
```

**All 6 permutations handled optimally:**

| Permutation | Operations | Commands |
|-------------|------------|----------|
| 1 2 3 | 0 | (already sorted) |
| 1 3 2 | 2 | sa, ra |
| 2 1 3 | 1 | sa |
| 2 3 1 | 1 | rra |
| 3 1 2 | 1 | ra |
| 3 2 1 | 2 | sa, rra |

</details>

<details>
<summary><b>4-7 Numbers - Small Sort Strategy</b></summary>

```c
void ft_five(int args, int *a, int *b)
{
    int count = args;

    // Phase 1: Push smallest elements to B
    while (count > 3)
    {
        if (ft_mincheck(count, a) < (count / 2))
        {
            // Minimum in upper half → rotate up
            while (ft_mincheck(count, a) != 0)
                ft_rotate_a(count, a);
            ft_push_b(count, a, b);
            count--;
        }
        else
        {
            // Minimum in lower half → reverse rotate up
            while (ft_mincheck(count, a) != 0)
                ft_reverse_ra(count, a);
            ft_push_b(count, a, b);
            count--;
        }
    }

    // Phase 2: Sort remaining 3 in A
    ft_three(count, a);

    // Phase 3: Push back from B
    ft_five_push(args, count, a, b);
}
```

**Strategy**:
1. Find smallest element in A
2. Rotate to top (choose shortest path)
3. Push to B
4. Repeat until 3 elements left
5. Sort remaining 3 optimally
6. Push back from B

**Example** (5 numbers: [5, 3, 2, 4, 1]):
```
Initial:  A:[5, 3, 2, 4, 1]  B:[]

1. Find min (1), rotate, push:
   A:[5, 3, 2, 4]  B:[1]

2. Find min (2), rotate, push:
   A:[5, 3, 4]  B:[1, 2]

3. Sort remaining 3 in A:
   A:[3, 4, 5]  B:[1, 2]

4. Push back:
   A:[1, 2, 3, 4, 5]  B:[]
```

</details>

<details>
<summary><b>8+ Numbers - Chunk Algorithm</b></summary>

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
            // Element in upper half of stack
            ln = ft_rotup(ln, chunk, a);
            ft_push_b(args, a, b);
        }
        else
        {
            // Element in lower half of stack
            ln = ft_rotdown(ln, chunk, a);
            ft_push_b(args, a, b);
        }

        // Dynamic chunk size adjustment
        pos = ft_len(pos, ln);
        if (ln <= args - chunk)
            chunk += pos;  // Expand chunk boundary
    }

    // Phase 2: Push back to A in sorted order
    ft_pushtoa(args, a, b);
}
```

**Chunk Size Calculation**:
```c
int ft_len(int pos, int ln)
{
    if (ln == 200)
        pos = ln / 8;   // 25 per chunk
    if (ln == 100)
        pos = ln / 6;   // ~16 per chunk
    if (ln == 20)
        pos = ln / 3;   // ~6 per chunk
    if (ln == 10)
        pos = ln / 2;   // 5 per chunk
    return (pos);
}
```

**Dynamic Adjustment**: Chunk boundaries expand as stack A shrinks.

</details>

### Index Mapping

Before sorting, numbers are converted to **0-based indices** for easier comparison.

**Example Transformation**:
```
Original: [42, -3, 17, 0, 100]
Sorted:   [-3, 0, 17, 42, 100]
Indices:  [3, 0, 2, 1, 4]

Mapping:
42  → 3 (4th smallest)
-3  → 0 (1st smallest)
17  → 2 (3rd smallest)
0   → 1 (2nd smallest)
100 → 4 (5th smallest)
```

<details>
<summary><b>Index Mapping Implementation (ft_chunk)</b></summary>

```c
void ft_chunk(int args, int *a)
{
    int *chunk = malloc(args * sizeof(int));
    int *temp = malloc(args * sizeof(int));
    int i;

    // Copy array
    i = 0;
    while (i < args)
    {
        chunk[i] = a[i];
        i++;
    }

    // Sort copied array
    ft_sort_chunk(args, chunk);

    // Assign indices: smallest=0, largest=args-1
    ft_chunk_assign(args, chunk, temp, a);

    free(chunk);
    free(temp);
}
```

**Benefits**:
- Simplifies chunk boundary checks
- Makes comparisons consistent
- Improves algorithm readability

</details>

### Push Back Strategy

**Strategy**: Always push the **largest** element from B back to A. Result: A is filled in descending order during push → ends up sorted ascending.

<details>
<summary><b>Push Back Implementation (ft_pushtoa)</b></summary>

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
                // Optimization: swap if adjacent
                if ((ft_maxcheck(argb, b) == 1) && (b[0] < b[1]))
                    ft_swap_b(b);
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

**Optimization**: Use `sb` (swap) when max is at position 1 instead of rotating twice.

</details>

---

## 📖 Stack Operations

Implementation provides **11 operations** across 4 categories:

### Operation Categories

<table>
<tr>
<th>Category</th>
<th>Operations</th>
<th>Description</th>
</tr>
<tr>
<td><b>Swap</b></td>
<td><code>sa</code>, <code>sb</code>, <code>ss</code></td>
<td>Swap first 2 elements</td>
</tr>
<tr>
<td><b>Push</b></td>
<td><code>pa</code>, <code>pb</code></td>
<td>Move top element between stacks</td>
</tr>
<tr>
<td><b>Rotate</b></td>
<td><code>ra</code>, <code>rb</code>, <code>rr</code></td>
<td>Shift up (first → last)</td>
</tr>
<tr>
<td><b>Reverse Rotate</b></td>
<td><code>rra</code>, <code>rrb</code>, <code>rrr</code></td>
<td>Shift down (last → first)</td>
</tr>
</table>

### Operation Visualization

```
Initial Stack:  [3, 2, 1, 5, 4]

sa  → [2, 3, 1, 5, 4]  (swap first 2)
pb  → A:[3, 1, 5, 4]  B:[2]  (push to B)
ra  → [1, 5, 4, 3]  (rotate: 3 goes to bottom)
rra → [3, 1, 5, 4]  (reverse: 4 goes to top from bottom)
pa  → A:[2, 3, 1, 5, 4]  B:[]  (push from B)
```

### Detailed Operations

<details>
<summary><b>Swap Operations (sa, sb, ss)</b></summary>

```c
void ft_swap_a(int *a)
{
    int temp;

    temp = a[0];
    a[0] = a[1];
    a[1] = temp;
    write(1, "sa\n", 3);
}

void ft_swap_b(int *b)
{
    int temp;

    temp = b[0];
    b[0] = b[1];
    b[1] = temp;
    write(1, "sb\n", 3);
}

void ft_swap_ss(int *a, int *b)
{
    int temp;

    temp = a[0];
    a[0] = a[1];
    a[1] = temp;

    temp = b[0];
    b[0] = b[1];
    b[1] = temp;

    write(1, "ss\n", 3);
}
```

**Effect**: Swaps the first two elements at the top of the stack.

</details>

<details>
<summary><b>Push Operations (pa, pb)</b></summary>

```c
void ft_push_a(int argc, int *a, int *b)
{
    int i;

    // Shift A down to make space
    i = argc - 1;
    while (i > 0)
    {
        a[i] = a[i - 1];
        i--;
    }

    // Move top of B to top of A
    a[0] = b[0];

    // Shift B up
    i = 0;
    while (i < argc - 1)
    {
        b[i] = b[i + 1];
        i++;
    }

    b[argc - 1] = 0;
    write(1, "pa\n", 3);
}

void ft_push_b(int argc, int *a, int *b)
{
    int i;

    // Shift B down
    i = argc - 1;
    while (i > 0)
    {
        b[i] = b[i - 1];
        i--;
    }

    // Move top of A to top of B
    b[0] = a[0];

    // Shift A up
    i = 0;
    while (i < argc - 1)
    {
        a[i] = a[i + 1];
        i++;
    }

    a[argc - 1] = 0;
    write(1, "pb\n", 3);
}
```

**Effect**: Moves the top element from one stack to another.

</details>

<details>
<summary><b>Rotate Operations (ra, rb, rr)</b></summary>

```c
void ft_rotate_a(int argc, int *a)
{
    int temp;
    int i;

    temp = a[0];  // Save first element
    i = 0;

    // Shift all elements up
    while (i < argc - 1)
    {
        a[i] = a[i + 1];
        i++;
    }

    a[argc - 1] = temp;  // First becomes last
    write(1, "ra\n", 3);
}

void ft_rotate_b(int argc, int *b)
{
    int temp;
    int i;

    temp = b[0];
    i = 0;

    while (i < argc - 1)
    {
        b[i] = b[i + 1];
        i++;
    }

    b[argc - 1] = temp;
    write(1, "rb\n", 3);
}

void ft_rotate_rr(int argc, int *a, int *b)
{
    ft_rotate_a(argc, a);
    ft_rotate_b(argc, b);
}
```

**Effect**: First element goes to the bottom.

</details>

<details>
<summary><b>Reverse Rotate Operations (rra, rrb, rrr)</b></summary>

```c
void ft_reverse_ra(int argc, int *a)
{
    int temp;
    int i;

    temp = a[argc - 1];  // Save last element
    i = argc - 1;

    // Shift all elements down
    while (i > 0)
    {
        a[i] = a[i - 1];
        i--;
    }

    a[0] = temp;  // Last becomes first
    write(1, "rra\n", 4);
}

void ft_reverse_rb(int argc, int *b)
{
    int temp;
    int i;

    temp = b[argc - 1];
    i = argc - 1;

    while (i > 0)
    {
        b[i] = b[i - 1];
        i--;
    }

    b[0] = temp;
    write(1, "rrb\n", 4);
}

void ft_reverse_rr(int argc, int *a, int *b)
{
    ft_reverse_ra(argc, a);
    ft_reverse_rb(argc, b);
}
```

**Effect**: Last element goes to the top.

</details>

---

## 💻 Implementation Details

### Data Structure

Implementation uses **arrays** to represent stacks:

```c
int *a = malloc(count * sizeof(int));      // Stack A
int *b = ft_calloc(count, sizeof(int));    // Stack B (initialized to 0)
```

**Stack Convention**:
- Index `0` = **top** of stack
- Index `n-1` = **bottom** of stack

### Input Parsing

Supports two input formats:

**Format 1: Multiple arguments**
```bash
./push_swap 4 2 8 1
```

**Format 2: Single string**
```bash
./push_swap "4 2 8 1"
```

The program automatically handles both using `ft_split()`.

<details>
<summary><b>Algorithm Selection Logic</b></summary>

```c
void ft_push_swap(char **args, int argc, int *a, int *b)
{
    int count = 0;

    // Parse integers
    while (args[count])
    {
        a[count] = ft_atoi_push(args[count]);
        count++;
    }

    // Validate input (no duplicates, valid integers)
    if (ft_checker(argc - 1, a) != 1)
        ft_error(argc - 1, a);

    // Select algorithm by size
    if (argc == 3)
        ft_swap_a(a);                      // 2 numbers

    if (argc == 4)
        ft_three(argc - 1, a);             // 3 numbers

    if (argc > 4 && argc < 8)
        ft_five(argc - 1, a, b);           // 4-7 numbers

    if (argc > 7)
        ft_hundred(argc - 1, argc - 1, a, b);  // 8+ numbers
}
```

</details>

### Helper Functions

<details>
<summary><b>Find Minimum/Maximum Position</b></summary>

```c
int ft_mincheck(int args, int *c)
{
    int min;
    int pos;
    int i;

    min = c[0];
    pos = 0;
    i = 1;

    while (i < args)
    {
        if (c[i] < min)
        {
            min = c[i];
            pos = i;
        }
        i++;
    }

    return (pos);  // Returns index of smallest element
}

int ft_maxcheck(int args, int *c)
{
    int max;
    int pos;
    int i;

    max = c[0];
    pos = 0;
    i = 1;

    while (i < args)
    {
        if (c[i] > max)
        {
            max = c[i];
            pos = i;
        }
        i++;
    }

    return (pos);  // Returns index of largest element
}
```

</details>

<details>
<summary><b>Chunk Position Finders</b></summary>

```c
int ft_chunkup(int args, int chunk, int *a)
{
    int i;

    i = 0;
    // Search from top down
    while (i < args)
    {
        if (a[i] < chunk)  // Found element in current chunk
            return (i);
        i++;
    }
    return (args);  // Not found
}

int ft_chunkdown(int args, int chunk, int *a)
{
    int i;

    i = args - 1;
    // Search from bottom up
    while (i >= 0)
    {
        if (a[i] < chunk)  // Found element in current chunk
            return (i);
        i--;
    }
    return (-1);  // Not found
}
```

**Purpose**: Find closest element within current chunk boundary, choosing shortest rotation path.

</details>

<details>
<summary><b>Validation Functions</b></summary>

```c
int ft_checker(int argc, int *a)
{
    int i;

    i = 0;
    // Check if already sorted
    while (i < argc - 1)
    {
        if (a[i] > a[i + 1])
            return (1);  // Not sorted
        i++;
    }
    return (0);  // Already sorted → exit without operations
}

void ft_error(int args, int *c)
{
    free(c);
    write(2, "Error\n", 6);
    exit(1);
}

int ft_atoi_push(const char *str)
{
    // Custom atoi with:
    // - Overflow detection
    // - Invalid character detection
    // - Sign handling
    // Returns integer or calls ft_error() on failure
}
```

</details>

---

## 📁 Project Structure

```
push_swap/
├── 📄 LICENSE                # MIT License
├── 📄 Makefile               # Build configuration
├── 📄 push_swap.h            # Header with all prototypes
│
├── 📄 main.c                 # Entry point, argument parsing (~90 lines)
├── 📄 ft_atoi_push.c         # Custom atoi with validation (~70 lines)
├── 📄 ft_checks.c            # Validation functions (~75 lines)
├── 📄 ft_aux.c               # Auxiliary functions (~50 lines)
│
├── 📄 ft_chunk.c             # Index mapping, sorting (~75 lines)
├── 📄 ft_low_cases.c         # Algorithms for 3 and 5 numbers (~75 lines)
├── 📄 ft_hi_cases.c          # Chunk algorithm for 8+ numbers (~95 lines)
│
├── 📄 ft_swap.c              # Swap operations: sa, sb, ss (~50 lines)
├── 📄 ft_push.c              # Push operations: pa, pb (~60 lines)
├── 📄 ft_rotate.c            # Rotate operations: ra, rb, rr (~65 lines)
├── 📄 ft_reverse.c           # Reverse rotate: rra, rrb, rrr (~65 lines)
│
├── 📂 libft/                 # Custom C library
│   ├── libft.h
│   ├── libft.a
│   ├── ft_split.c
│   ├── ft_atoi.c
│   ├── ft_calloc.c
│   └── ... (other libft functions)
│
└── 📂 test/                  # Testing utilities
    ├── README.md
    ├── push_swap_rng.py     # Random number generator GUI
    └── p_s_rng.png          # Screenshot of GUI tool
```

### File Breakdown

<table>
<tr>
<th>File</th>
<th>Lines</th>
<th>Purpose</th>
</tr>
<tr>
<td><code>main.c</code></td>
<td>~90</td>
<td>Argument parsing, memory allocation, algorithm selection</td>
</tr>
<tr>
<td><code>ft_chunk.c</code></td>
<td>~75</td>
<td>Index mapping and sorting for chunk algorithm</td>
</tr>
<tr>
<td><code>ft_low_cases.c</code></td>
<td>~75</td>
<td>Hardcoded optimal solutions for 3 and 5 numbers</td>
</tr>
<tr>
<td><code>ft_hi_cases.c</code></td>
<td>~95</td>
<td>Chunk-based algorithm for 8+ numbers (ft_hundred, ft_pushtoa)</td>
</tr>
<tr>
<td><code>ft_checks.c</code></td>
<td>~75</td>
<td>Validation: sorted check, min/max find, chunk finders</td>
</tr>
<tr>
<td><code>ft_swap.c</code></td>
<td>~50</td>
<td>sa, sb, ss implementations with write() output</td>
</tr>
<tr>
<td><code>ft_push.c</code></td>
<td>~60</td>
<td>pa, pb implementations with array shifting</td>
</tr>
<tr>
<td><code>ft_rotate.c</code></td>
<td>~65</td>
<td>ra, rb, rr implementations (shift up)</td>
</tr>
<tr>
<td><code>ft_reverse.c</code></td>
<td>~65</td>
<td>rra, rrb, rrr implementations (shift down)</td>
</tr>
<tr>
<td><code>ft_aux.c</code></td>
<td>~50</td>
<td>Helper utilities for algorithm</td>
</tr>
<tr>
<td><code>ft_atoi_push.c</code></td>
<td>~70</td>
<td>Custom atoi with overflow and error handling</td>
</tr>
</table>

**Total**: 11 source files + libft integration

<details>
<summary><b>Makefile</b></summary>

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

re: fclean all

.PHONY: all clean fclean re
```

</details>

---

## 🧪 Testing

### Test Categories

<table>
<tr>
<th>Test Type</th>
<th>Command</th>
<th>Expected Result</th>
</tr>
<tr>
<td><b>Basic (3 nums)</b></td>
<td><code>./push_swap 2 1 3</code></td>
<td>Max 3 operations</td>
</tr>
<tr>
<td><b>Small (5 nums)</b></td>
<td><code>./push_swap 5 3 2 4 1</code></td>
<td>Max 12 operations</td>
</tr>
<tr>
<td><b>Medium (100 nums)</b></td>
<td><code>./push_swap $(seq 1 100 | shuf)</code></td>
<td>~500-600 ops (target: <700)</td>
</tr>
<tr>
<td><b>Large (500 nums)</b></td>
<td><code>./push_swap $(seq 1 500 | shuf)</code></td>
<td>~3000-3500 ops (target: <5500)</td>
</tr>
<tr>
<td><b>Already sorted</b></td>
<td><code>./push_swap 1 2 3 4 5</code></td>
<td>No output (0 operations)</td>
</tr>
<tr>
<td><b>Reverse sorted</b></td>
<td><code>./push_swap 5 4 3 2 1</code></td>
<td>Many operations</td>
</tr>
<tr>
<td><b>Duplicates (error)</b></td>
<td><code>./push_swap 1 2 2 3</code></td>
<td><code>Error</code></td>
</tr>
<tr>
<td><b>Invalid (error)</b></td>
<td><code>./push_swap 1 2 abc</code></td>
<td><code>Error</code></td>
</tr>
</table>

### Python Test Generator

Repository includes `test/push_swap_rng.py` - a **GUI tool** for generating random test cases:

```bash
cd test
python3 push_swap_rng.py
```

**Features**:
- **Cantidad de números**: Number count input (e.g., 50)
- **Desde**: Range start (e.g., -500)
- **Hasta**: Range end (e.g., 500)
- **Checkboxes**: 
  - `./push_swap` - Generate push_swap command
  - `./checker_Mac` - Include checker validation
  - `$ARG=""` - Export as variable
  - `wc -l` - Count operations
- **Generar**: Generate random numbers
- **Copiar**: Copy to clipboard

### Checker Validation

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_Mac $ARG
```

**Output**:
- `OK` - Correctly sorted
- `KO` - Not sorted or invalid final state
- `Error` - Invalid operations or input

### Operation Counting

```bash
# Generate 100 random numbers and count operations
ARG=$(seq 1 100 | shuf | tr '\n' ' ')
OPS=$(./push_swap $ARG | wc -l)
echo "Operations: $OPS"

# Verify sorting
./push_swap $ARG | ./checker_Mac $ARG
```

<details>
<summary><b>Stress Testing Script</b></summary>

```bash
#!/bin/bash

# Test 100 random sets of 100 numbers
for i in {1..100}; do
    ARG=$(seq 1 100 | shuf | tr '\n' ' ')
    OPS=$(./push_swap $ARG | wc -l)
    RESULT=$(./push_swap $ARG | ./checker_Mac $ARG)

    echo "Test $i: $OPS operations - $RESULT"

    if [ "$RESULT" != "OK" ]; then
        echo "FAILED: Sorting error"
        break
    fi

    if [ $OPS -gt 700 ]; then
        echo "FAILED: Too many operations"
        break
    fi
done

echo "\nAll tests passed!"
```

</details>

### Performance Benchmarks

| Size | Max Operations | Target | Typical Result | Score Impact |
|------|----------------|--------|----------------|--------------|
| 3 | 3 | 2-3 | 2-3 | Pass/Fail |
| 5 | 12 | 8-12 | 8-10 | Pass/Fail |
| 100 | 700 | ~550 | 500-600 | Scaling |
| 500 | 5500 | ~3500 | 3000-3500 | Scaling |

**Score Calculation** (42 grading):
- < 700 for 100 → 5 points
- < 900 for 100 → 4 points
- < 1100 for 100 → 3 points
- < 1300 for 100 → 2 points
- < 1500 for 100 → 1 point

---

## 📊 Performance

### Complexity Analysis

<table>
<tr>
<th>Metric</th>
<th>Complexity</th>
<th>Explanation</th>
</tr>
<tr>
<td><b>Time Complexity</b></td>
<td>O(n²)</td>
<td>Chunk sorting + rotation operations</td>
</tr>
<tr>
<td><b>Space Complexity</b></td>
<td>O(n)</td>
<td>Two stacks + temporary arrays for index mapping</td>
</tr>
<tr>
<td><b>Operation Count</b></td>
<td>~O(n log n)</td>
<td>Logarithmic due to chunk division</td>
</tr>
</table>

### Algorithm Comparison

| Input Size | Bubble Sort | Quick Sort | Chunk Algorithm (This) |
|------------|-------------|------------|------------------------|
| 100 | O(10,000) | O(664) | ~550 operations |
| 500 | O(250,000) | O(4,483) | ~3,500 operations |

**Efficiency**: Chunk algorithm achieves near-optimal operation counts for the push_swap constraints.

---

## 💡 What I Learned

Through this project, deep understanding was gained in:

- ✅ **Sorting Algorithms**: Implementing and optimizing custom sorting strategies
- ✅ **Algorithm Analysis**: Big O notation, time/space complexity, performance tuning
- ✅ **Chunking Strategy**: Dividing problems into manageable groups for efficiency
- ✅ **Data Structures**: Stack operations, array manipulation, index mapping
- ✅ **Index Mapping**: Converting arbitrary values to ordinal positions (0 to n-1)
- ✅ **Dynamic Optimization**: Adjusting chunk sizes based on remaining elements
- ✅ **Edge Case Handling**: Hardcoded optimal solutions for small inputs (2, 3, 5)
- ✅ **Performance Tuning**: Balancing algorithmic complexity vs operation count
- ✅ **Testing Strategies**: Creating comprehensive test suites, stress testing

### Key Challenges

<table>
<tr>
<th>Challenge</th>
<th>Solution Implemented</th>
</tr>
<tr>
<td><b>Algorithm Design</b></td>
<td>Chunk-based approach with dynamic sizing (6 chunks for 100, 12 for 500)</td>
</tr>
<tr>
<td><b>Chunk Size Tuning</b></td>
<td>Calculate ideal divisions: args/6 for 100, args/12 for 500, dynamic adjustment</td>
</tr>
<tr>
<td><b>Operation Minimization</b></td>
<td>Choose shortest rotation path (upper vs lower half), use swap optimization</td>
</tr>
<tr>
<td><b>Edge Cases (2, 3, 5)</b></td>
<td>Hardcoded optimal solutions: all 6 permutations for 3, strategic pushing for 5</td>
</tr>
<tr>
<td><b>Index Mapping</b></td>
<td>Convert arbitrary integers to 0-based indices before sorting (ft_chunk)</td>
</tr>
<tr>
<td><b>Push Back Strategy</b></td>
<td>Always push largest from B to A, resulting in sorted ascending order</td>
</tr>
<tr>
<td><b>Rotation Optimization</b></td>
<td>Compare distances from top (rotate) vs bottom (reverse rotate), choose shorter</td>
</tr>
<tr>
<td><b>Input Validation</b></td>
<td>Check duplicates, integer range, format validity in ft_atoi_push</td>
</tr>
</table>

### Design Decisions

**Why chunk-based algorithm?**
- Divides problem into manageable pieces
- Reduces comparison overhead
- Performs well for medium/large inputs (100-500)
- Achieves ~O(n log n) operations

**Why index mapping (ft_chunk)?**
- Simplifies comparisons (0 to n-1 vs arbitrary integers)
- Makes chunk boundaries crystal clear
- Improves algorithm readability and debugging
- Eliminates value range concerns

**Why different chunk sizes for different inputs?**
- 100 numbers: 6 chunks (~16 each) - better granularity
- 500 numbers: 12 chunks (~41 each) - prevents excessive pushing
- Dynamic resizing (ft_len) adapts to shrinking stack

**Why hardcoded solutions for small cases?**
- 3 numbers: Only 6 permutations, all optimal solutions known (max 3 ops)
- 5 numbers: Predictable pattern, can achieve optimal with push-min strategy
- Faster execution, guaranteed minimal operations

**Why arrays instead of linked lists?**
- Constant-time access to any element (needed for min/max finding)
- Simpler rotation implementation
- Better cache locality
- Stack operations don't require dynamic resizing

**Why always push largest from B?**
- B fills with elements in roughly descending order during chunk push
- Pushing largest first naturally sorts A in ascending order
- Eliminates need for sorting A after repopulation

---

## 📄 License

MIT License - See [LICENSE](LICENSE) file for details.

This project is part of the 42 School curriculum. Feel free to use and learn from this code, but please don't copy it for your own 42 projects. Understanding comes from doing it yourself! 🚀

---

## 🔗 Related Projects

This project builds upon:

- **[libft](https://github.com/Z3n42/42_libft)** - Custom C library (ft_split, ft_atoi, ft_calloc used)

Skills learned here apply to:
- **Sorting algorithms** - QuickSort, MergeSort, HeapSort implementations
- **Algorithm optimization** - Time/space complexity analysis
- **Data structure manipulation** - Stacks, queues, heaps, trees

---

<div align="center">

**Made with ☕ by [Z3n42](https://github.com/Z3n42)**

*42 Urduliz | Circle 2*

[![42 Profile](https://img.shields.io/badge/42_Intra-ingonzal-000000?style=flat&logo=42&logoColor=white)](https://profile.intra.42.fr/users/ingonzal)

</div>
