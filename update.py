#!/usr/bin/env python

import os
from urllib import parse

HEADER = """#
# 백준, 프로그래머스 문제 풀이 목록
"""

def main():
    content = HEADER
    root_categories = ["백준", "프로그래머스"]

    for root_category in root_categories:
        if not os.path.isdir(root_category):
            continue

        content += f"\n## 📚 {root_category}\n"

        for difficulty in sorted(os.listdir(root_category)):
            diff_path = os.path.join(root_category, difficulty)
            if not os.path.isdir(diff_path):
                continue

            content += f"\n<details>\n<summary><strong>🚀 {difficulty}</strong></summary>\n\n"
            content += "| 문제번호 | 링크 | 개념 |\n"
            content += "| -------- | ---- | ---- |\n"

            problem_dirs = sorted(os.listdir(diff_path))
            for problem in problem_dirs:
                problem_path = os.path.join(diff_path, problem)
                if not os.path.isdir(problem_path):
                    continue

                problem_link = "-"
                concept_links = []

                for file in sorted(os.listdir(problem_path)):
                    if file.endswith(".md"):
                        md_path = parse.quote(os.path.join(problem_path, file))
                        if file == "README.md":
                            problem_link = f"[문제 설명]({md_path})"
                        else:
                            title = file[:-3]  # remove .md
                            concept_links.append(f"[{title}]({md_path})")

                content += f"| {problem} | {problem_link} | {concept_links[0] if concept_links else '-'} |\n"
                for concept in concept_links[1:]:
                    content += f"| | | {concept} |\n"

            content += "\n</details>\n"

    with open("README.md", "w", encoding="utf-8") as fd:
        fd.write(content)

if __name__ == "__main__":
    main()
