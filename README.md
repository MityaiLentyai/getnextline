<center>

*This project has been created as part of the 42 curriculum by dzzayats*

</center>

# Description

**get_next_line** reads a line from a file descriptor, one line at a time. It is
written in C as part of the 42 curriculum and uses a **linked list** to store
unprocessed data read from the file.

Each call to `get_next_line` returns a newly allocated string containing the
next line, including the trailing `\n` when present. When there is nothing left
to read, the function returns `NULL`.

## Project files

| File | Created | Description |
|------|---------|-------------|
| `get_next_line.h` | 2026/07/16 | Header: `t_list` struct, `BUFFER_SIZE`, prototypes |
| `get_next_line.c` | 2026/07/16 | Core logic: read, extract, and return the next line |
| `get_next_line_utils.c` | 2026/07/16 | Linked-list helpers: node creation and list utilities |
| `main.c` | 2026/07/28 | Demo program that reads and prints lines from a text file |
| `test_1.txt` | — | Sample input file used by `main.c` |

## Data structure

```c
typedef struct s_list
{
	ssize_t         bytes_read;
	ssize_t         current_byte;
	char            *current_line;
	char            *stashed_line;
	struct s_list   *next;
}   t_list;
```

- `current_line` — buffer filled by `read()`
- `bytes_read` — number of bytes stored in the buffer
- `current_byte` — index of the next unread character in the buffer
- `stashed_line` — reserved for leftover data (unused, set to `NULL`)
- `next` — pointer to the next node in the list

## Functions

### `get_next_line.c`

| Function | Description |
|----------|-------------|
| `read_until_nl` | Reads from `fd` and appends nodes until a `\n` is found or EOF |
| `copy_line_from_lst` | Copies the next line from the linked list into a new string |
| `advance_stash` | Moves the read position forward and frees empty nodes |
| `get_next_line` | Returns the next line from file descriptor `fd` |

### `get_next_line_utils.c`

| Function | Description |
|----------|-------------|
| `init_node` | Initializes a list node after a successful `read()` |
| `create_node` | Allocates a node and reads up to `BUFFER_SIZE` bytes from `fd` |
| `lst_has_newline` | Returns `1` if a `\n` exists in unconsumed list data |
| `lst_line_len` | Returns the length of the next line (including `\n` if present) |
| `lst_clear` | Frees every node and its buffer in the list |

# Instructions

## Compilation

`BUFFER_SIZE` defaults to `42` in the header and can be overridden at compile
time:

```bash
gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 \
	get_next_line.c get_next_line_utils.c main.c -o gnl
```

To build only the library sources (without the demo):

```bash
gcc -Wall -Wextra -Werror -c get_next_line.c get_next_line_utils.c
```

## Usage

Run the demo program. It opens `test_1.txt`, prints each line, and frees it:

```bash
./gnl
```

Expected output:

```
Line 1: First line
Line 2: Second line
Line 3: Fourth; line??? 
Line 4: No _ LIES - THIS IS THE FOURTH LINE
```

### Test file 1 (`test_1.txt`)

```
First line
Second line
Fourth; line??? 
No _ LIES - THIS IS THE FOURTH LINE
```
# Resources

- `man 2 read`
- `man 2 open`
- `man 3 malloc`

