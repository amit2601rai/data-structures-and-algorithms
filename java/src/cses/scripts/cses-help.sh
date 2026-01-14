#!/bin/bash

# Quick reference for CSES workflow

cat << 'EOF'
╔═══════════════════════════════════════════════════════════════╗
║                    CSES Workflow Scripts                      ║
╚═══════════════════════════════════════════════════════════════╝

📝 CREATE NEW SOLUTION
   ./cses-new.sh
   ./cses-new.sh https://cses.fi/problemset/task/1131/
   → Creates Solution.java with CP template (no package)
   → Fetches problem name and sample I/O from CSES link

🧪 TEST SOLUTION LOCALLY
   ./cses-run.sh                  (auto-uses input if exists)
   ./cses-run.sh mytest
   echo "input" | ./cses-run.sh
   → Compiles and runs with test input
   → Shows expected output if available

📦 ARCHIVE SOLVED PROBLEM
   ./cses-archive.sh ProblemName
   → Moves to solved/ProblemName.java with package

───────────────────────────────────────────────────────────────

🔄 COMPLETE WORKFLOW EXAMPLE:

   1. ./cses-new.sh https://cses.fi/problemset/task/1131/
      (creates Solution.java with problem info + sample I/O)

   2. [Edit ../Solution.java in IDE]
      (implement your solution)

   3. ./cses-run.sh
      (auto-tests with fetched input)

   4. [Submit to CSES and get ACCEPTED ✓]

   5. ./cses-archive.sh TreeDiameter
      (archives solution, creates new template)

───────────────────────────────────────────────────────────────

📂 DIRECTORY STRUCTURE:

   cses/
   ├── Solution.java          ← Active (no package, with problem link)
   ├── input                  ← Auto-fetched sample input
   ├── output                 ← Auto-fetched expected output
   ├── scripts/
   │   ├── cses-new.sh
   │   ├── cses-run.sh
   │   └── cses-archive.sh
   └── solved/
       └── TreeDiameter.java  ← Archived (package cses.solved)

───────────────────────────────────────────────────────────────

💡 RESULT FORMAT:
   • 1/Success: <message>     - Operation succeeded
   • 2/Failure: <details>     - Operation failed

💡 TIPS:
   • Provide CSES URL to auto-fetch problem details
   • Files named 'input' and 'output' (no extensions)
   • ./cses-run.sh auto-detects and uses input
   • Compare your output with expected output automatically

EOF

