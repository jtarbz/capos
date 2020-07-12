# capos
This is the repository for my OS design senior research project, which explores
the effects of security on the experience of personal computing as well as the
process of operating system design as a whole. Its name stands for Capstone OS,
which is in my opinion a brilliantly intuitive and clever name, indicative of
great naming sense.

The operating system is targeted towards the 32-bit Intel i386 architecture in
order to take advantage of its more-simple design and the vast wealth of
resources pertaining to its implementation.

# design
The most basic concept behind capos is eliminating the delineation between
kernel space and user space, removing security in order to allow a user to have
more complete access to the computer. This is not to say that security is an
unimportant aspect of operating system design, but rather to highlight its
restriction on personal computing. In addition, capos should be as modular as
possible with its procedures so as to allow for effective comparison and testing
of different implementations for resource allocation, scheduling, and all that
other fun OS stuff.

As of now, capos employs a monolithic kernel design, with all procedures being
compiled directly into the kernel before runtime and those procedures meant to
be accessible to a user added to a universal function key.

This project is a work in progress, and anything stands to change at the drop of
a hat.

# credit, where due
A big thank you to the people over at the OSdev wiki for getting me started with
the information for OS design / programming, and to Kustaa Nyholm for his tiny
printf implementation, which has been incredibly useful for debugging.

# licensing
Stay tuned!
