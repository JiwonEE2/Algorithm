#!/usr/bin/env python

import os
import html
from urllib import parse

HEADER = """#
# 백준, 프로그래머스 문제 풀이 목록
"""

def main():
    content = HEADER
    root_dirs = ["백준", "프로그래머스"]

    for site in root_dirs:
        site_path = os.path.join(".", site)
        if not os.path.isdir(site_path):
            continue

        content += f"\n## 📚 {site}\n"

        for difficulty in sorted(os.listdir(site_path)):
            diff_path = os.path.join(site_path, difficulty)
            if not os.path.isdir(diff_path):
                continue

            content += f"<details>\n<summary><strong>🚀 {difficulty}</strong></summary>\n\n"
            content += "| 문제번호 | 개념 |\n"
            content += "| -------- | ---- |\n"

            for problem_number in sorted(os.listdir(diff_path)):
                prob_path = os.path.join(diff_path, problem_number)
                if not os.path.isdir(prob_path):
                    continue

                problem_display = problem_number
                concept_links = []

                for file in sorted(os.listdir(prob_path)):
                    if not file.endswith(".md"):
                        continue

                    file_path = os.path.join(prob_path, file)
                    md_path = parse.quote(file_path)

                    if file == "README.md":
                        problem_display = f"[{problem_number}]({md_path})"
                    else:
                        title = html.escape(file[:-3])  # <, > 같은 문자 처리
                        concept_links.append(f"[{title}]({md_path})")

                if concept_links:
                    content += f"| {problem_display} | {concept_links[0]} |\n"
                    for concept in concept_links[1:]:
                        content += f"|  | {concept} |\n"
                else:
                    content += f"| {problem_display} | - |\n"

            content += "\n</details>\n"

    with open("README.md", "w", encoding="utf-8") as fd:
        fd.write(content)

if __name__ == "__main__":
    main()
