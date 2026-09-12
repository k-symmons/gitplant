#!/bin/sh
printf '%s:%s' "$(basename "$(pwd)")" "$(git log --max-count=1 --format=%H)" >> events.txt
