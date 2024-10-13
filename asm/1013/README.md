### What's the TOP LEVEL of writing asm? ###
####        ---- "I'm the Complier"

step 1: adstract a complicated state transition ( S1 -> S2 )
step 2: draw the parser tree of "S1 -> S2" ( if has )
step 3: Topological-Sort and Generate Target Code (like 8086 asm)
