io.write("Running test 'jumps.lua'\n")
os.execute("mkdir Output")
os.execute("casm ../Tests/jumps.casm -S -o Output/test_jumps.S")
os.execute("casm ../Tests/jumps.casm -Sc -o Output/test_jumps.c")
os.execute("casm ../Tests/jumps.casm -o Output/test_jumps.exe")