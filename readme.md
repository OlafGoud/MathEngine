# Mathengine
Description

## Features
Math operators

## Getting started

Donload? versions

## Compiled setup

### Prerequisites
- C++ compiler
- Cmake

### Building
```sh
git clone
cmake -DCMAKE_POLICY_VERSION_MINIMUM=3.5 -DCMAKE_EXPORT_COMPILE_COMMANDS=ON -B build -S source
cmake --build ./build --parallel

# for clangd
ln -s build/compile_commands.json compile_commands.json 

```

**Dependencies**

> [!CAUTION]
> Distributions of Waybar are only released on the [official GitHub page](https://github.com/Alexays/Waybar).<br/>
> Waybar does **not** have an official website. Do not trust any sites that claim to be official.
