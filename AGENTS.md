# AGENTS.md

This file documents how automated agents (and contributors) should build, test, lint and style code in this repository. It is written for agents that will operate in this workspace and assume the working directory is the repository root.

Quick overview
- Primary languages: C++ (C++20), Python, Go, JavaScript, Java
- Canonical C++ source dir: `cpp-template`
- Common data-structures: `common/ListNode.cpp`, `common/TreeNode.cpp`
- Recommended build system for C++: CMake (project includes `build/compile_commands.json`)

Caveat
- This repository contains many single-file LeetCode solutions (filenames like `1.两数之和.cpp`). Many files include `../common/*.cpp` directly for easy local compilation. When authoring new code prefer headers for shared types; do not change existing files without a clear reason.

Cursor / Copilot rules
- Repository scan result (at the time of writing): No `.cursor/rules/` or `.cursorrules` found; no `.github/copilot-instructions.md` found.
- If such rules are added later, obey them and update this AGENTS.md accordingly. When present, copy rule snippets into this document and follow them strictly.

References
- See `README.md` for project structure and `CLAUDE.md` for a high-level developer note.

Environment assumptions
- Typical toolchain available: `g++` or `clang++` (C++20), `cmake`, `make` / `ninja`, `python3` (>=3.8), `go` (>=1.18), `node` (>=14), `mvn` (Maven).
- On Windows, Visual Studio 2022/2026 is supported for C++ solutions; a `.slnx` may exist for IDE-driven builds.

Build / test / lint commands (summary)
- C++ (single-file compile + run)
  - Linux/macOS: `g++ -std=c++20 "cpp-template/<file>.cpp" -O2 -Wall -Wextra -o /tmp/out && /tmp/out`
  - Windows (cmd/powershell): `g++ -std=c++20 "cpp-template/<file>.cpp" -O2 -Wall -Wextra -o out.exe && .\out.exe`
  - Use the single-file compile pattern when the file includes `main()` or relies on local `../common/*.cpp` includes.
- C++ (CMake project)
  - Configure and build (from repo root):
    - `cmake -S cpp-template -B build -DCMAKE_BUILD_TYPE=Release` (or `-S . -B build` if CMakeLists is at repo root)
    - `cmake --build build --config Release -- -j`  # builds all targets
  - Clean: `cmake --build build --target clean`
  - Language servers / static tools can use `build/compile_commands.json` if present.
- Go
  - Run all tests: `go test ./...`
  - Run package tests: `go test ./go-template/leetcode/editor/cn`
  - Run a single test by name: `go test ./go-template/leetcode/editor/cn -run TestName` (regex)
  - Format: `gofmt -w .` (or `gofmt -w <path>`)
  - Lint (recommended): `golangci-lint run` (install separately)
- Python
  - Run a single file: `python3 python-template/leetcode/editor/cn/merge-two-sorted-lists.py`
  - Run pytest: `pytest -q path/to/test_file.py::test_name` or `pytest -q` to run all
  - Format: `black .`
  - Import sort: `isort .`
  - Lint: `flake8 .` (configure if/when added)
- JavaScript / Node
  - Run single JS file: `node js-template/leetcode/editor/cn/merge-two-sorted-lists.js`
  - Tests (if added): `npx jest path/to/test.spec.js -t "test name"`
  - Lint: `eslint .` (recommended)
  - Format: `prettier --write .`
- Java (Maven)
  - Build: `mvn -f java-template/pom.xml compile`
  - Run tests: `mvn -f java-template/pom.xml test`

How to run "a single test" (language-specific)
- C++: compile the single file (or the CMake target that includes it). Example: `g++ -std=c++20 "cpp-template/1.两数之和.cpp" -o out && ./out`.
- Go: `go test <pkg> -run TestName`
- Python (pytest): `pytest -q path/to/test_file.py::test_function`
- Java (Maven surefire): `mvn -Dtest=TestClass#testMethod test`
- JS (Jest): `npx jest path/to/test.spec.js -t "test name"`

Code style guidelines (for agents editing code)
- General rules
  - Be conservative: do not reformat or refactor unrelated files. Keep changes minimal and focused.
  - Preserve existing file-level conventions (many filenames contain Chinese text and LeetCode ids).
  - Add tests for behavior-changing code where reasonable.
  - Avoid adding new third-party dependencies unless approved.
  - Never commit secrets or credentials; report them to maintainers if found.

- Imports & includes
  - C++: prefer `#include "foo.hpp"` for shared types. Avoid changing existing `.cpp` includes en masse. For new shared definitions, create headers under `common/` or `include/` and use include guards (`#pragma once` acceptable).
  - Python: use absolute imports within package structure when applicable. Keep stdlib, third-party, then local imports (isort enforces this).
  - Go: use standard package import ordering; run `goimports` to fix imports.
  - JS/TS: group imports (external libs, absolute project imports, relative). Let eslint autofix handle ordering where configured.

- Formatting
  - C++: use `clang-format` (Google or LLVM style). Run `clang-format -i <files>` only on changed files.
  - Python: use `black .` and `isort .`.
  - Go: `gofmt` / `goimports`.
  - JS: `prettier --write .`.
  - Java: follow Maven project's configured formatter (run `mvn formatter:format` if available).

- Naming and types
  - C++: Classes/structs PascalCase (Solution, ListNode); functions and methods camelCase (`twoSum`); variables camelCase; constants `kPrefix` (e.g., `constexpr int kMax = 10;`). Avoid `using namespace std;` in headers.
  - Go: idiomatic short names for locals; exported names PascalCase.
  - Python: snake_case for functions and variables; PascalCase for classes. Add type hints for public APIs where practical.
  - JS: camelCase for variables and functions; PascalCase for React components (if any).
  - Java: standard Java conventions (PascalCase classes, camelCase methods/variables).

- Error handling
  - C++: prefer returning error codes or empty containers in algorithmic solutions rather than throwing. Use RAII and smart pointers; avoid raw `new`/`delete`.
  - Go: always check and return errors; wrap with context using `fmt.Errorf("...: %w", err)`.
  - Python: raise specific exceptions; catch narrow exception types.
  - JS: prefer Promises/async-await with proper try/catch; avoid swallowing errors.

- Forbidden practices
  - Do not use `as any`, `@ts-ignore`, or `@ts-expect-error` to silence type errors.
  - Do not delete failing tests to make CI pass.
  - Do not commit build artifacts (avoid committing `build/` outputs unless necessary and approved).

Testing guidance
- Unit tests exist for Go under `go-template` (`*_test.go`). Use `go test` to run them.
- C++: few standardized unit tests; test by compiling the relevant file and running local inputs. If adding tests, prefer GoogleTest and add CMake entries.
- Python/JS: if you add tests, use `pytest` or `jest` respectively and include instructions in PR description.

Git workflow & commit guidelines
- Keep commits small and focused; PRs should include a short summary and bullet list of changes.
- Do not use destructive git commands (force-push to main/master) without approval.
- Do not amend or rebase public commits without explicit instruction. Avoid `--no-verify` on commits unless necessary and explained.
- If you must create a new branch for a feature or fix, use `feature/` or `fix/` prefixes: `git checkout -b feature/short-description`.

Editing rules for agents (strict)
- Read the target file before editing.
- Prefer minimal `edit` operations that replace only the necessary block. Do NOT reformat entire repo.
- If adding new files, follow repo structure:
  - C++ solutions: `cpp-template/`
  - Python: `python-template/`
  - Go: `go-template/`
  - JS: `js-template/`
  - Java: `java-template/`
- Frontend visual changes (styles, layout, animation) must be delegated to a UI/UX engineer agent. Logic-only changes in frontend files are allowed.
- Never use `@ts-ignore`, `as any`, or other type-suppression hacks.

When to ask a human / escalate
- Changes that will reformat many files or change shared API (e.g., changing `ListNode` structure).
- Adding new build tools, CI config, or credentials: escalate for approval.
- Platform-specific build failures (Windows Visual Studio) requiring manual debugging.

Failure recovery
- If a change breaks the build or tests, revert to last known good state and document steps attempted.
- After 3 failed attempts to fix a problem, stop, revert, and escalate to maintainers with a clear failure log.

Notes & rationale
- The repository is primarily an educational collection of LeetCode solutions. Preserve instructional comments and the per-file standalone nature of solutions.
- Be conservative with cross-file refactors—many solutions intentionally include `common/*.cpp` for easy local compilation.

Contact / author
- Author: repository owner (see README) — prefer opening an Issue or PR for large changes.

If you want me to also generate a `clang-format` config, ESLint/Prettier config, or a small GoogleTest harness for C++, tell me which one and I will prepare it.
