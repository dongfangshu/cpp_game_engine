# Skills

Each top-level directory under this tree is a self-contained [Agent Skill](https://www.anthropic.com/news/agent-skills) for one area of Xmake. Skills are grouped by **when an agent would reach for them** — the category is a hint about the kind of task you're working on, not a strict technical taxonomy. Categories are documented in [`docs/categories/`](./docs/categories/).

## Layout

```
skills/
├── README.md               # this index
├── docs/
│   └── categories/         # one index per category (not scanned as a skill)
│       ├── <category>.md
│       └── move-manifest.txt
├── <skill-name>/           # every skill is a DIRECT child of this directory
│   ├── SKILL.md            # frontmatter + instructions
│   ├── references/         # optional: supporting docs (loaded on demand)
│   └── scripts/            # optional: helper scripts
```

### Why the tree is flat

DSH's filesystem skill provider scans a root **one level deep** — it recognizes exactly
`<root>/<name>/SKILL.md` and `<root>/<name>.md`, and nested `**/SKILL.md` files are
deliberately not discovered. A `<category>/<skill>/SKILL.md` layout therefore yields **zero**
skills: the agent sees no catalog, the `/` menu is empty, and `skill <name>` fails with
"unknown or no longer available".

So: **never nest a skill under a category directory.** A *new* top-level directory that
contains only a `README.md` is skipped harmlessly, but a skill under it is invisible.

Each `SKILL.md` has a frontmatter block with `name` and `description` — the agent reads the
description to decide whether to load the full instructions. `name` must be kebab-case
(`^[a-z0-9]+(?:-[a-z0-9]+)*$`) and unique across the tree; the directory name is free-form but
conventionally matches.

## Categories

### [basics](./docs/categories/basics.md)

Getting started — installation, first project, idiomatic style, templates.

- xmake-basics, xmake-style, xmake-templates

### [project-config](./docs/categories/project-config.md)

Core `xmake.lua` APIs — targets, options, packages, rules, probes, link control, policies.

- xmake-targets, xmake-options, xmake-packages, xmake-rules
- xmake-feature-check, xmake-link-order, xmake-policy

### [cli](./docs/categories/cli.md)

Running xmake from the command line and exporting to other build systems.

- xmake-commands, xmake-introspection, xmake-project-generator, xmake-trybuild

### [toolchains](./docs/categories/toolchains.md)

Compiler selection, cross-compilation, C++20 modules.

- xmake-toolchains, xmake-cross-compilation, xmake-cxx-modules, xmake-zigcc

### [packages](./docs/categories/packages.md)

C/C++ packages — `xrepo`, recipes, private repos, network acceleration.

- xrepo-cli, xrepo-env, xmake-network
- xmake-repo-testing, xmake-debug-package-source, xmake-private-packages

### [packaging](./docs/categories/packaging.md)

Producing distributable artifacts (zip, deb, nsis, …).

- xmake-xpack

### [testing](./docs/categories/testing.md)

Tests for your project and for xmake itself.

- xmake-tests, xmake-unit-tests

### [performance](./docs/categories/performance.md)

Build-speed knobs — caches, distributed compilation, remote builds, optimization playbook.

- xmake-build-optimization, xmake-build-cache
- xmake-distributed-compilation, xmake-remote-compilation

### [scripting](./docs/categories/scripting.md)

Writing Lua inside `xmake.lua` — scripts, modules, plugins/tasks, async jobs, graphs, color output.

- xmake-scripting, xmake-script-modules
- xmake-plugins, xmake-custom-plugins
- xmake-async-jobs, xmake-graph-module, xmake-color-output
- xmake-addons, xmake-addon-development

### [ops](./docs/categories/ops.md)

Running and debugging xmake itself — env vars, themes, troubleshooting, dev builds.

- xmake-env-vars, xmake-theme, xmake-troubleshooting, xmake-dev

### [languages](./docs/categories/languages.md)

Building non-C/C++ languages — per-language skills with target kinds, toolchains, interop.

- xmake-rust, xmake-go, xmake-swift, xmake-objc
- xmake-dlang, xmake-fortran, xmake-cuda, xmake-zig
- xmake-nim, xmake-pascal, xmake-vala, xmake-csharp, xmake-kotlin

### [ai](./docs/categories/ai.md)

Agent integrations shipped as skills.

- xmake-harness

## Authoring notes

- Keep each `SKILL.md` focused — the `description` field is what the agent reads to decide whether to load the skill, so make it specific about *when* to use it.
- Put long reference material under `references/` so `SKILL.md` stays small.
- Ground every example in real, verified Xmake behavior — no invented APIs.
- Cross-link between skills with a "When to branch out" section at the bottom.
- When adding a new skill, create `.agents/skills/<skill-name>/SKILL.md` **at the top level** (never under a category directory) and add a line to the matching file under `docs/categories/`.

## Total

58 skills across 12 categories.
