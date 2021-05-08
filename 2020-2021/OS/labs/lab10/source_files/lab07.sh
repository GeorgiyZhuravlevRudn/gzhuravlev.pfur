#!/bin/bach
HELL=Hello
function hello{
    LOCAL HELLO=World
    echo $HELLO
}
hello
echo $HELLO

#!/bin/bach
HELL=Hello
function hello{
    LOCAL HELLO=World
    echo $HELLO
}

echo $HELLO

LOCAL HELLO

