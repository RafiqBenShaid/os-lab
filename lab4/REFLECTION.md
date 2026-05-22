# Reflection

The hardest concept in this lab was understanding how
 process creation and execution work together using
 fork(), exec(), and wait(). At first it was confusing
 why the same code sometimes produced different output
 orders, but later I understood that the operating system
 scheduler controls process execution, which causes
 non-deterministic behavior. One concept that clicked
 unexpectedly was how exec() replaces the current process
 image completely while keeping the same PID. I also found
 it interesting to observe system calls using strace and
 understand how user programs communicate with the kernel.
 Among the project ideas, I would like to attempt building
 a small custom shell later because it combines process
 management, pipes, redirection,
 and command execution in a practical way.
