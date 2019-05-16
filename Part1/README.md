# Mutex and Channel basics

### What is an atomic operation?
> Atomic operations are program operations that run completely independently of other processes. This is because they are often used in the kernel. Will never be left in an incomplete state.

### What is a semaphore?
> A semaphore works as a flag for a resource which is shared between multiple threads, and tells wheter the resource is currently being used. It is incremented or decremented, and what it represents depends on the implementation and developer. A semaphore must be indivisible, i.e. a semaphore must be toggled by an atomic operation.

### What is a mutex?
> A mutex is a locking mechanism, used to ensure that only one task can access a resource at any given time.

### What is the difference between a mutex and a binary semaphore?
> The main difference between a mutex and a binary semaphore is that a semaphore is a signaling mechanism, whereas mutex is a locking mechanism. Mutexes stricly prevents other tasks from accessing a resource when the resource is used by a task; a binary semaphore informs a task when or if it should start. More detailed, a binary semaphore can be incremented/decremented by any part of a program; a mutex can only be unlocked by the thread which locked it.

### What is a critical section?
> A critical section is a part of a task which, in concurrent programming, accesses a shared resurce, and therefore can lead to unexpected or wrong behaviour if handled incorrectly. A critical section is usually protected, ensuring it cannot be executed by more than one process at a time.

### What is the difference between race conditions and data races?
> A race condition is when multiple threads are using a resource simultaneously, and therefore the result depends on the ordering in time. A data race occurs when two instructions from different threads access the same memory location and at least one of them is a write access. The main difference is that a race condition is a semantic error, which means that the ordering of actions matters for the outcome, whereas a data race is a program error. It is however to be noted that a race condition can be caused by a data race. A deadlock is an example of a race condition.

### List some advantages of using message passing over lock-based synchronization primitives.
> The biggest advantage of message passing over lock-based or bottleneck syncronization primitives is that message passing allows for concurrency, avoiding data races. This allows for more parallell hardware, which makes message passing more tolerant of higher communication latencies. Message passing also makes the program more scalable.

### List some advantages of using lock-based synchronization primitives over message passing.
> Lock-based synchronization has the advantage of being simpler to handle in smaller programs, whereas message passing might lead to some very complex bugs and errors. However, in larger programs, lock-based synchronisation might also grow very complex. Lock-based gives less overhead than message passing, i.e. is faster, req. less memory, etc.
