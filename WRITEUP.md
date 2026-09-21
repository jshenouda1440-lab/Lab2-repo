# ECE 412 -- Lab 2 Writeup

**Name:**
**EID:**
**Machine used (hostname):**

*Answer in your own words -- two to four sentences each unless noted. These are the explanation points of the rubric; code alone does not earn them.*

---

## W1. Why is `struct DB` in `db.cpp` and not `db.h`?

State what a client of `db.h` can and cannot do with a `DB` when the struct definition is hidden.
 Give one concrete misuse (a line of code) that the hidden layout physically prevents.
A client of db.h cannot directly modify struct defintitions, however they can call functions defined in db.cpp.
an example of misuse would be db->cap = 99;.
## W2. Deep copy of names

`DB_add(db, 42, "Ada", 3.9)` must NOT store the caller's `"Ada"` pointer -- it must `my_strdup` 
its own copy. In one or two sentences, describe the dangling-pointer bug you would create if you stored the caller's 
pointer directly. Which valgrind category would that show up as?

if the cleint were to free the name and we did not have a copy stored we woud be left with a pointer to invalid memory 
valgrind would catch this and say its an invalid read of size x. 
## W3. Why does `DB_find` return `const Record *`?

Explain what a client could do with a non-const `Record *` that would break the ADT's invariants.
 Give two concrete misuses (`free(r->name)` is one -- what is another?).
If we returned a non const Record * the client could access the pointer values directly and write into them
free(r->name) and r->id =1; would be another misuse 
## W4. Removal strategy

Which did you pick for `DB_remove`: **shift the tail down** or **swap the last element into the gap**? 
Why? State the big-O of your choice and the one visible side effect (order preserved vs. not).

I chose to swap the last element in because its really easy to do. However the order is not preserved when doing so.

Then walk through, by hand, removing the last element of a 3-element DB using your strategy. 
Off-by-one at the last element is the specific bug this exercise catches.

find index 2 
free everything at index 2 
db->items[2] = db->items[3 - 1]
db->count = 2;
## W5. `DB_destroy` order

You free `items[i].name` for each `i`, then `db->items`, then `db`. What goes wrong if you do it in the OPPOSITE order 
(free `db` first, or free `db->items` before the names)? Which valgrind category catches each?
if you free db first you have no way to access the items[i] and they would get lost in memory. defiently lost in valgrind. inavlid read/write 
errors
## W6. Growth policy

State your starting capacity, your growth factor, and the capacity sequence your >= 20-record
 driver actually produced. Confirm that `sizeof(Record)` (not `sizeof(int)`) is what you passed to 
`malloc`/`realloc` -- one sentence on why hard-coding a number here would break the moment we added a field to `Record`.
the starting capacity is 4. the growth factor is doubling. the capcity sequnce was 4, 8, 16, 32. Because hard coding a number makes the code
ineleastic to change of the size of Record. If you added a field record can increase by an unknown amount making the hard code break.
## W7. Save/load round trip

Show one line from your `records.txt`, one line from your `bad_records.txt`, and describe how `DB_load` decides the second one is 
malformed. What does your `DB_load` do to the DB when it encounters the bad line -- roll back, keep partial, something else? 
Whatever you chose, say so plainly.
records.txt:
record.txt ; 17,name17,3.85
bad_records.txt: 18,name18
DB_load decides if its malformed by using fscanf. it shoudl return a value of 3 if its correct, and if it doesnt its malformed
it keeps partial data. naything before the bad line is kept.

## W8. Separate compilation

Run:

```
touch main.cpp
make
```
g++ -std=c++11 -Wall -Wextra -Werror -g -c main.cpp -o main.o
g++ -std=c++11 -Wall -Wextra -Werror -g mystr.o db.o main.o -o db
Paste the `make` output. Only `main.o` and the final link should rebuild -- `db.o` and `mystr.o` 
must NOT recompile. If they do, your Makefile is doing "recompile everything on any change" and you lose the separate-compilation points.

## W9. The valgrind summary (paste)

==1688719==
==1688719== HEAP SUMMARY:
==1688719==     in use at exit: 0 bytes in 0 blocks
==1688719==   total heap usage: 56 allocs, 56 frees, 102,943 bytes allocated
==1688719==
==1688719== All heap blocks were freed -- no leaks are possible
==1688719==
==1688719== For lists of detected and suppressed errors, rerun with: -s
==1688719== ERROR SUMMARY: 0 errors from 0 contexts (suppressed: 0 from 0)

Paste the `HEAP SUMMARY` through `ERROR SUMMARY` block of

`valgrind --leak-check=full --show-leak-kinds=all ./db`

It must show 0 errors, 0 bytes definitely lost, 0 bytes indirectly lost.

```
(paste here)
```

## W10. AI assistance

Name **one specific bug you had to fix in AI-suggested code** on this lab -- or state plainly that you wrote the lab unaided. AI-assisted lines in your source carry the syllabus citation comment.

Two common ones on this lab, if you need a starting point: (a) the assistant put `struct DB { ... }` in `db.h`, killing the 15 opacity points; (b) `DB_remove` shifted the array down without `free(items[i].name)` first, leaking every removed name.
I wrote the majority of it unaided , so i had no problem with the ai giving me incorrect info.
## W11. Anything that fought you *(optional, genuinely useful)*
I forgot to actually implement the str functions so i had to debug code for that. oops
