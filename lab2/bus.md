# BUG REPORT

## Bug 1: NULL Pointer Dereference
Problem:
Dereferencing NULL pointer caused segmentation fault.

How Found:
Used gdb and print p.

Fix:
Avoid dereferencing NULL pointers.

---

## Bug 2: Off-by-One Error
Problem:
Loop used <= instead of <.

How Found:
Used gdb breakpoint and inspected i.

Fix:
Changed condition to i < n.

---

## Bug 3: Memory Leak
Problem:
malloc memory not freed.

How Found:
Used valgrind.

Fix:
Added free().
