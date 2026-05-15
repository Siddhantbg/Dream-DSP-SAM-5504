#!/usr/bin/env python3
"""Parse dsp1.c..dsp4.c NRPN tables and emit C++ ParamDescriptor rows (reference)."""

import re
import sys
from pathlib import Path

# Repo layout: firmware at repo root, GUI in SAM5504EvalGUI/
FIRMWARE_DIR = Path(__file__).resolve().parents[1]


def parse_nrpn_list(c_path: Path) -> list[tuple[int, int]]:
    text = c_path.read_text(encoding="utf-8", errors="ignore")
    block = re.search(r"nrpn\d+List\[.*?\]\s*=\s*\{([^}]+)\}", text, re.S)
    if not block:
        return []
    rows = []
    for m in re.finditer(r"\{\s*(0x[0-9A-Fa-f]+)\s*,\s*(0x[0-9A-Fa-f]+)\s*\}", block.group(1)):
        rows.append((int(m.group(1), 16), int(m.group(2), 16)))
    return rows


def main() -> int:
    root = FIRMWARE_DIR
    if not root.is_dir():
        print(f"Firmware folder not found: {root}", file=sys.stderr)
        return 1

    for i in range(1, 5):
        path = root / f"dsp{i}.c"
        print(f"// {path.name}")
        for nrpn, fn in parse_nrpn_list(path):
            print(f"  // ch={i-1} nrpn=0x{nrpn:04X} fn=0x{fn:04X}")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
