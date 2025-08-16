#!/usr/bin/env bash
set -euo pipefail

exec </dev/tty >/dev/tty 2>&1

default="new_prjct_name"

while :; do
    echo -e "Name of the new project to be created: \n"
    read -e -r -i "$default" -p "> " name
    name="$(printf "%s" "$name" | sed -e 's/^[[:space:]]*//' -e 's/[[:space:]]*$//')"

    if [ -z "$name" ]; then
        echo "Please enter a non-empty name." >&2
        default=""
        continue
    fi

    case "$name" in
        *[!A-Za-z0-9._-]*)
            echo "Only A-Z a-z 0-9 . _ - are allowed." >&2
            default="$name"
            continue
            ;;
    esac

    if [ -e "$name" ]; then
        echo "Path '$name' already exists, pick another." >&2
        default="$name"
        continue
    fi

    printf "%s\n" "$name"
    break
done
