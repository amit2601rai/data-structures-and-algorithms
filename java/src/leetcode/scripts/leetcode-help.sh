#!/bin/bash

# Quick reference for LeetCode workflow

cat << 'EOF'
╔═══════════════════════════════════════════════════════════════╗
║                  LeetCode Workflow Scripts                    ║
╚═══════════════════════════════════════════════════════════════╝

📝 CREATE NEW SOLUTION
   ./leetcode-new.sh
   ./leetcode-new.sh 1 TwoSum
   → Creates Solution.java with CP template (no package)
   → Adds problem number and name as comments
   → Includes LeetCode method signature section

🧪 TEST SOLUTION LOCALLY (Optional)
   ./leetcode-run.sh
   → Compiles and runs solve() method for testing
   → Most problems tested directly on LeetCode

📦 ARCHIVE SOLVED PROBLEM
   ./leetcode-archive.sh TwoSum
   → Moves to solved/TwoSum.java with package

───────────────────────────────────────────────────────────────

🔄 COMPLETE WORKFLOW EXAMPLE:

   1. ./leetcode-new.sh 1 TwoSum
      (creates Solution.java with problem info)

   2. [Copy method signature from LeetCode]
      (paste in the commented section)

   3. [Implement solution]
      (write code in both solve() and LeetCode method)

   4. [Optional: Test locally with ./leetcode-run.sh]

   5. [Copy LeetCode method and submit]

   6. ./leetcode-archive.sh TwoSum
      (archives solution, creates new template)

───────────────────────────────────────────────────────────────

📂 DIRECTORY STRUCTURE:

   leetcode/
   ├── Solution.java          ← Active (no package, dual structure)
   ├── scripts/
   │   ├── leetcode-new.sh
   │   ├── leetcode-run.sh    (optional for local testing)
   │   └── leetcode-archive.sh
   └── solved/
       └── TwoSum.java        ← Archived (package leetcode.solved)

───────────────────────────────────────────────────────────────

💡 TIPS:
   • Copy method signature from LeetCode to commented section
   • Implement solution in the LeetCode method
   • Test locally in solve() if needed
   • Copy only the LeetCode method to submit
   • No need for input/output files - test on LeetCode directly

EOF

