import os

run = os.fork()
if run == 0:
    print("CHILD: " +  str(os.getpid()))
    os._exit(0)
else:
    os.wait()
    print("PARENT: " +  str(os.getpid()))
script = "a='Hello World'\nprint(a)"
exec(script)
