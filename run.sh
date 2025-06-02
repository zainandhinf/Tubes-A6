CC=gcc
OUTPUT_DIR=out
EXECUTABLE=$OUTPUT_DIR/main.exe

mkdir -p $OUTPUT_DIR

$CC -o $EXECUTABLE main.c sll.c kartu.c queue.c stack.c uno.c deck.c player.c avl.c menu.c

if [ $? -eq 0 ]; then
    echo "Compilation successful. Running the program..."
    ./$EXECUTABLE
else
    echo "Compilation failed. See errors above."
    exit 1
fi