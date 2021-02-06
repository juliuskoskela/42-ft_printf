README

name | prototype | description
-----|-----------|------------
dl_del_node | `void l_del_node(t_dlist **ref, t_dlist *del)` | Delete node `del` in the list. 
dl_del_node_at | `void l_del_node_at(t_dlist **ref, uint64_t pos)` | Delete node in position `pos`. 
dl_putafter | `void l_putafter(t_dlist **ref, t_dlist *prev, void *new)` | Put node `new` after node `prev` in the list. 
dl_putlast | `void l_putlast(t_dlist **ref, void *new)` | Put node `new` in the end of the list. 
dl_putbefore | `void l_putbefore(t_dlist **ref, t_dlist *next, void *new)` | Put node `new` before node `next` in the list. 
dl_del_last | `void l_del_last(t_dlist **ref)` | Delete las node in the list. 
dl_del_last | `uint64_t l_len(t_dlist *node)` | Return lenght of the list. 
dl_putfirst | `void l_putfirst(t_dlist **ref, void *new)` | Put node `new` in the beginning of the list. 
dl_del_last | `t_dlist dl_get_last(t_dlist **list)` | Return a pointer to the last element in the list. 
dl_print | `void l_print_s(t_dlist *node)` | Print list. 
dl_protate | `void l_rotate(t_dlist **head_ref, uint64_t n)` | Rotate list by `n` steps. 
dl_del_list | `void l_del_list(t_dlist *ref)` | Delete list. 
is_alnum | `int s_alnum(int c)` | Returns 1 if `c` is an alphanumeric character. 
is_upper | `int s_upper(int c)` | Returns 1 if `c` is uppercase. 
is_lower | `int s_lower(int c)` | Returns 1 if `c` is lowercase. 
is_alpha | `int s_alpha(int c)` | Returns 1 if `c` is an alpha character. 
is_print | `int s_print(int c)` | Returns 1 if `c` is a printable character. 
is_ascii | `int s_ascii(int c)` | Returns 1 if `c` is an ascii character. 
is_neg | `int s_neg(int n)` | Returns 1 if `c` is a negative number. 
is_wspace | `int s_wspace(char c)` | Returns 1 if `c` is a whitespace character. 
is_digit | `int s_digit(int c)` | Returns 1 if `c` is a digit. 
s_del | `void _del(char **as)` | String delete; delete string by freeing a pointer to the string passedby reference. Does not wipe the contents! 
s_str | `char s_str(const char *h, const char *n)` | Locate substring; locates the first occurrence of thenull-terminated string `n` in the string `h`. Characters that appearafter a `\0' character are not searched. 
s_ncat | `char s_ncat(char *s1, const char *s2, uint64_t n)` | String catenate (n); appends a copy of `n` characters from thenull-terminated string s2 to the end of the null-terminated string s1.The string s1 must have sufficient space to hold the result. 
s_cat | `char s_cat(char *s1, const char *s2)` | The string catenate function appends a copy of the null-terminatedstring s2 to the end of the null-terminated string s1, then adds aterminating `\0'. The string s1 must have sufficient space to holdthe result. 
s_nstr | `char s_nstr(const char *h, const char *n, uint64_t len)` | Locate substring (n); function locates the first occurrence of thenull-terminated string `n` in the string `h`, where not more than lencharacters are searched.  Characters that appear after a `\0' characterare not searched. 
s_chr | `char s_chr(const char *s, int c)` | The `s_chr` function locates the first occurrence of `c` (converted to achar) in the string pointed to by `s`. The terminating null character isconsidered to be part of the string; therefore if `c` is `\0`, thefunction locates the terminating `\0`. 
s_lcpy | `uint64_t _lcpy(char *dst, const char *src, uint64_t size)` | String copy; copies `size` contents from `src` to `dst`. Destination stringmust be able to hold the contents of `src`.Returns the lenght of the copied string. 
s_clr | `void _clr(char *s)` | String clear; replaces all characters in `s` with a null terminatingcharacter. 
s_len | `uint64_t _len(const char *s)` | String lenght; returns the lenght of the null terminated string `s`. 
s_join | `char s_join(char const *s1, char const *s2)` | Join strings `s1` and `s2`.Returns a memory allocated output `out`. 
s_sum | `int _sum(char *str)` | Return the sum of all elements in string `str`. 
s_equ | `int _equ(char const *s1, char const *s2)` | String equals; if the two strings are equal, returns 1. Otherwisereturns 0. 
s_lenc | `int _lenc(char *s, char c)` | String lenght (c); returns the lenght until the first occurence of `c` inthe null terminated string `s` or 0 if c doesn't occur. 
s_nequ | `int _nequ(char const *s1, char const *s2, uint64_t n)` | String equal (n); compares `n` characters from strings `s1` and `s2`and returns 1 if the strings are equal. 
s_sub | `char s_sub(char const *s, unsigned int start, uint64_t len)` | Substring duplicate; Duplicate contents of `s` starting from index `start`for lenght `len`.Return a memory allocated output `out`. 
s_cdup | `char s_cdup(const char *s1, char c)` | String duplicate (c); duplicate contents from outing `s1` untildelimiting character `c`.Returns a memory allocated output `out`. 
s_ncmp | `int _ncmp(const char *s1, const char *s2, uint64_t n)` | String compare (n); lexicographically compares `n` characters in thenull-terminated strings `s1` and `s2`.Returns 0 if strings are identical. Otherwise it returns the difference(in integers) between the first non-matching characters in the strings. 
s_cmp | `int _cmp(const char *s1, const char *s2)` | String compare; exicographically compares the null-terminatedstrings `s1` and `s2`.Returns 0 if strings are identical. Otherwise it returns the difference(in integers) between the first non-matching characters in the strings. 
s_join_free | `char s_join_free(char *s1, char *s2, size_t flag)` | Join strings `s1` and `s2`. Frees the string referred to by `flag`.0 = no free1 = `s1` is freed2 = `s2` is freed3 = both strings are freedReturns a memory allocated output `out`. 
s_new | `char s_newc(size_t size, int c)` | String new; create an allocated string of size `size` format string with`c`. 
s_chr | `char s_rchr(const char *s, int c)` | The `s_chr` function locates the last occurrence of `c` (converted to achar) in the string pointed to by `s`. The terminating null character isconsidered to be part of the string; therefore if `c` is `\0`, thefunction locates the terminating `\0`. 
s_ctoc | `void _ctoc(char *str, int from, int to)` | Convert all occurences of `from` to `to` in the string `str`. 
s_mapi | `char s_mapi(char const *s, char (*f)(unsigned int, char))` | String map; applies function `f` on all elements of string `out` and storesthe results in string `out`. Unlike s_iter it passes the index asparameter to function `f`.Returns a memory allocated output `out`. 
s_trim | `char s_trim(char const *s)` | Allocates (with malloc(3)) and returns a copy of the string given asargument without whitespaces at the beginning or at the end of the string.Will be considered as whitespaces the following characters ’ ’, ’\n’ and’\t’. If s has no whites- paces at the beginning or at the end, thefunction returns a copy of s. If the allocation fails the functionreturns NULL. 
s_ndup | `char s_ndup(const char *s, uint64_t n)` | String duplicate (n); duplicate `n` characters from `s1`.Returns a memory allocated output `out`. 
s_rev | `char s_rev(char *str)` | String reverse; reverses the string `str`. 
s_sub | `char s_csub(char *s, char c)` | Substring duplicate from; Duplicate contents of `s` starting from char `c`until the end of `s`.Return a memory allocated output `out`. 
s_cdup | `char s_dup(const char *s1)` | String duplicate (c); duplicate contents from string `s1`.Returns a memory allocated output `out`. 
s_new | `char s_new(uint64_t size)` | String new; create an allocated string of size `size`. 
s_appendc | `char s_appendc(char *str, char c)` | Append char `c` to the end of `str`. If `str` is empty create it. 
s_lcat | `uint64_t _lcat(char *dst, const char *src, uint64_t size)` | String catenate (l); Append `size` characters from `src` to the end of`dst`. Destination string must be able to hold the results(inc. NULL char).Returns the size of the whole string after catenation. 
s_iter | `void _iteri(char *s, void (*f)(unsigned int, char *))` | Perform function `f` (that takes an argument of type `char *` as wellas the index `i`) passed as a function pointer on all elements ofstring `s`. 
s_map | `char s_map(char const *s, char (*f)(char))` | String map; applies function `f` on all elements of string `out` and storesthe results in string `out`.Returns a memory allocated output `out`. 
s_ncpy | `char s_ncpy(char *dst, const char *src, uint64_t n)` | String copy (n); copies `n` characters from`src` to `dst`. Destinationstring must be able to hold the contents of `src`. 
s_cpy | `char s_cpy(char *dst, const char *src)` | String copy; copies the contents of `src` to `dst`. Destination stringmust be able to hold the contents of `src`. 
s_split | `char *s_split(char const *s, char c)` | Split the string `s` by the delimiting character `c` into an array ofstrings `tab`.Returns an array of strings. 
s_iter | `void _iter(char **ref, int (*fptr)(int c))` | Perform function `f` (that takes an argument of type `char *`) passed asa function pointer on all elements of string `s`. 
ht_print | `void t_print(t_htable *tab)` | Printt hash table `tab`. 
hash1 | `size_t ash1(char *key)` | Hashing method 1. 
ht_delete | `void t_delete(t_htable *tab, char *key)` | Delete hash item `key` from table `tab`. 
ht_insert | `int t_insert(t_htable *tab, char *key, void *val, size_t bt)` | Insert value `val` into hash table `tab` with the key value of `key`.Bt is the size of the data in `val`. 
ht_create | `t_htable ht_create(size_t (*hf)(char *), size_t size)` | Create hash table of size `size`. 
ht_search | `void ht_search(t_htable *tab, char *key)` | Search hash item of value `key` from the table `tab`. 
c_tolower | `int _toupper(int c)` | Convert a character (passed as an int) into lowercase. 
c_itoa_base | `char c_itoa_base(int64_t nb, int64_t base)` | Convert `nb` base 10 converted to a string of characters in base `base`. 
c_itoa | `char c_itoa(int64_t n)` | Convert an int into a string.Add for compatibility:if (n == -2147483648)return (s_cpy(str, "-2147483648")); 
c_atoi | `int _atoi(const char *str)` | Convert a string to an integer. 
c_tolower | `int _tolower(int c)` | Convert a character (passed as an int) into uppercase. 
c_itoa_base | `int _atoi_base(const char *str, int64_t base)` | Convert an integer to base `base` and output a string. 
c_bitoa | `char c_bitoa(uint64_t nb, uint64_t len)` | Convert a an int to a bit representation in chars. 
c_ftoe | `char c_ftoe(double nbr)` | Convert double `nbr` into scientific notation in ascii. 
c_ftoa | `char c_ftoa(double nbr, size_t p)` | Convert double `nbr` to a string of characters with decimal precision `p`. 
c_atof | `double _atof(const char *str)` | Convert a string of characters into a float. 
fd_addendl | `void d_addendl(char const *s, int fd)` | Add a string to a file and terminate with newline. 
fd_addnbr | `void d_addnbr(int n, int fd)` | Add a number to a file. 
fd_readline | `int d_readline(const int fd, char **line)` | Read a line from a file and put the line into the string `line` passedby reference. Subsequent calls to the function will get the next lineuntill end of file or if file descriptor is closed. 
fd_addstr | `void d_addstr(char const *s, int fd)` | Add a string to a file. 
fd_addchar | `void d_addchar(char c, int fd)` | Add a character to a file. 
p_endl | `void _endl(char const *s)` | Printf string `s` and print a newline at the end. 
p_str | `void _str(char const *s)` | Print string `s`. 
p_bits | `void _bits(uint64_t nb, uint64_t size)` | Print `size` bits from the integer `nb`. 
p_nbr | `void _nbr(int n)` | Print number `n` in ascii characters. 
p_char | `void _char(char c)` | Print char `c`. 
p_dlist_s | `void _dlist_s(t_dlist **list)` | Print the contents of list with void content as char strings. 
m__dgr | `double _dgr(double rad)` | Convert radians to degrees. 
m_log | `int64_t _log(int64_t n)` | Calculate the base 2 logarithm of n. 
m_prime | `uint64_t _prime(uint64_t n)` | Calculate if `n` is a prime number and return 1 if so. 
m_modf | `double _modf(double x, double *iptr)` | Convert double x into a decimal representation. Function returns mantissaand integral part is stored in the previously allocated int pointer `iptr`. 
m_pow | `` | Calculate `base` raised to the `exp`th power. 
m_sin | `double _sin(double x, int64_t p)` | Calculate sine of `x` with precision `p`. 
m__digits_base | `size_t _dcnt(uint64_t nb, uint64_t base)` | Calculate number of digits in `nb` in `base`. floor(log(nb) / log(base) 
m_fabs | `if (n < 0)` | Return the absolute (positive) value of a floating point number. 
m_cos | `double _cos(double x, int64_t p)` | Calculate cosine of `x` with precision `p`.Idea for optimization; save both sine and cosine when each is invoked. 
m_sqrt | `double _sqrt(double n)` | Calculate square root of n.Method from: https://tinyurl.com/yy2ksnwu 
m__floor | `double _floor(double x)` | Ceiling function maps to the least integer less than or equal to. 
m_nextprime | `uint64_t _nextprime(uint64_t n)` | Calculate the next prime number from `n` (even if `n` is prime). 
m_fac | `int64_t _fac(int64_t n)` | Calculate the factorial of n. 
m_intlen | `int _intlen(int64_t n)` | Calculate the lenght of an integer in base 10. 
m_primefac | `t_dlist m_primefac(uint64_t n)` | Calculates the prime factorials of `n` and returns a linked list withthe results. 
m_ceil | `double _ceil(double f)` | Ceiling function maps to the least integer greater than or equal toLogic:1. Small numbers get rounded to 0 or 1, depending on their sign2. Numbers without fractional bits are mapped to themselves3. Round the number down by masking out the fractional bits4. Positive numbers need to be rounded up, not down 
m_rad | `double _rad(double dgr)` | Convert degrees `dgr` to radians. 
b_fldcol | `uint64_t _fldcol(uint64_t *field, uint64_t col, uint64_t size)` | Get column `col` from the bit-field `field` from the area denoted by `size`. 
b_fldmoveup | `void _fldmoveup(t_field *field, uint64_t steps)` | Move field up in its container by 1 step. 
b_fldminus | `void _fldminus(t_field *board, t_field *field)` | Substract `field` rows from the rows in `board. 
b_fldplus | `void _fldplus(t_field *board, t_field *field)` | Add `field` rows from the rows in `board. 
b_fldoverlap | `int _fldoverlap(t_field *board, t_field *field)` | If fields overlap at any position inside the container of `board` return 0.Otherwise return 1. 
b_fldmoveright | `void _fldmoveright(t_field *field, uint64_t steps)` | Move field right in its container by 1 step. 
b_fldprint | `void _fldprint(t_field *field)` | Print field. 
b_flddel | `void _flddel(t_field *field)` | Delete field. 
b_lowest | `uint64_t _lowest(uint64_t nb, uint64_t size)` | Get the position of the lowest bit. 
b_fldinit | `uint64_t b_fldinit(uint64_t size)` | Initialize a field with 0. 
b_highest | `uint64_t _highest(uint64_t nb, uint64_t size)` | Get the position of the highest bit. 
b_fldmovedown | `void _fldmovedown(t_field *field, uint64_t steps)` | Move field down in its container by 1 step. 
b_fldsize | `void _fldsize(t_field *field)` | Calculate new size of `field`. 
b_fldfill | `int _fldfill(uint64_t *field, char *file, char one, uint64_t size)` | Fill the field from a file. Characters of the value `one` are 1 and allother caracters are 0. 
b_fldmoveleft | `void _fldmoveleft(t_field *field, uint64_t steps)` | Move field left in its container by 1 step. 
b_checknth | `uint64_t _checknth(uint64_t nb, int n)` | Check nth bit from number `nb`. 
b_fldcmp | `int _fldcmp(t_field **f1, t_field **f2)` | Compare fields `f1` and f2`. Return 1 if fields are identical. Otherwisereturn 0. 
b_fldclear | `void _fldclear(t_field *field)` | Clear bit-field. 
b_atonb | `uint64_t _atonb(char *str, char c, uint64_t size)` | Convert a string into bits. Characters of value `c` are considered 1and all other values are considered 0. 
b_fldnew | `t_field b_fldnew(uint64_t w, uint64_t h)` | Create a new field. Allocates memory for a fiel of size `w * h`. 
b_fldup | `t_field b_flddup(t_field *src)` | Duplicated field. Allocates the necessary memory. 
v_alloc | `void v_alloc(uint64_t size)` | Void memory allocation; allocates `size` bytes of memory and initializesthe memory. 
v_ccpy | `void v_ccpy(void *dst, const void *src, int c, uint64_t n)` | Void memory copy (c); copies bytes from string src to string dst.  Ifthe character c (as converted to an unsigned char) occurs in the stringsrc, the copy stops and a pointer to the byte after the copy of c in thestring dst is returned.  Otherwise, n bytes are copied, and a NULLpointer is returned. 
v_set | `void v_set(void *s, int c, uint64_t n)` | Void memory set; sets `n` bytes of memory pointed to by `s` with value `c`. 
v_chr | `void v_chr(const void *s, int c, uint64_t n)` | Void memory search; function locates the first occurrence of `c`(converted to an unsigned char) in string `s`.The `v_chr` function returns a pointer to the byte located, or NULL ifno such byte exists within `n` bytes. 
v_del | `void _del(void **ap)` | Void memory delete; frees the pointer `ap` passed by reference andand sets it to `NULL`. 
v_ccpy | `void v_cpy(void *dest, const void *src, uint64_t n)` | Void memory copy; copies `n` bytes from memory area `src` to memory area`dst`. If `dst` and `src` overlap, behavior is undefined. Applications inwhich `dst` and `src` might overlap should use `v_move` instead. 
v_bzero | `void _bzero(void *s, uint64_t n)` | Void memory formatting; formats `n` bytes of memory pointed to by `s`. 
v_chr | `int _cmp(const void *s1, const void *s2, uint64_t n)` | Void memory compare; compares byte string `s1` against byte string `s2`.Both strings are assumed to be n bytes long.The `v_chr` function returns zero if the two strings are identical, oth-erwise returns the difference between the first two differing bytes(treated as unsigned char values, so that `\200' is greater than `\0',for example). Zero-length strings are always identical. 
v_move | `void v_move(void *dest, const void *src, uint64_t n)` | Void memory move; copies `len` bytes from string `src` to string `dst`.The two strings may overlap; the copy is always done in a non-destructivemanner. 
v_calloc | `void v_calloc(uint64_t nmemb, uint64_t size)` | Void memory allocation (c); allocates and formats `nmemb` amount ofelements of size `size`. 
error | `void rror(char *message)` | Prints an error message passed as an argument and exists the program. 
mtx_free | `void tx_free(t_mtx *mtx)` | Free matrix. 
mtx_transpose | `void tx_transpose(t_mtx *mtx, t_mtx *src)` | Transopse matrix `src` and write the result in a previously allocatedmatrix `mtx`. 
vct_mag | `double ct_mag(double *vct, size_t size)` | Calculate vector magnitude. 
mtx_get_row | `void tx_get_row(double *row, t_mtx *mtx, size_t index)` | Get a row of matrix `mtx` at `index`. 
vct_norm | `double vct_norm(double *vct, size_t size)` | Normalize vector `vct`. 
mtx_clear | `void tx_cpy(t_mtx *dest, t_mtx *orig)` | Clear matrix. 
mtx_multiply | `int tx_multiply(t_mtx *mtx, t_mtx *a, t_mtx *b)` | Multiply `a * b`. Store the result in an allocated matrix `mtx` passedas a parameter. 
vct_opp | `double vct_opp(double *vct, size_t size)` | Calculate the opposite unit vector of `vct`. 
mtx_get_col | `void tx_get_col(double *col, t_mtx *mtx, size_t index)` | Get a column `col` of matrix `mtx` at `index`. 
vct_dot | `double ct_dot(double *a, double *b, size_t size)` | Dot-product of vector a * b. 
mtx_new | `t_mtx mtx_new(char *name, size_t rows, size_t cols)` | Create a new matrix. 
mtx_clear | `void tx_clear(t_mtx *mtx)` | Clear matrix. 
mtx_arr_multiply | `int tx_arr_multiply(t_mtx *mtx, t_mtx **arr, size_t size)` | Multiply an array of matrices in a decending order. Put the resultin an allocated array 'mtx`. 
mtx_print | `void tx_print(t_mtx *mtx)` | Formatted printing algorithm for a matrix. Markdown compliant output. 
vct_cross | `double vct_cross(double *a, double *b, size_t size)` | Cross-product of vector a * b. 
