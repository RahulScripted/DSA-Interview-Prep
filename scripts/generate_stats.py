#!/usr/bin/env python3
import subprocess
import os
from collections import Counter, defaultdict

def get_commit_data():
    """Extract daily commit counts from git log"""
    try:
        log = subprocess.check_output(
            ["git", "log", "--date=short", "--pretty=format:%ad"],
            cwd=os.path.dirname(os.path.dirname(__file__))
        ).decode().strip().split("\n")
        
        if log == ['']:
            return {}
        
        commit_count = Counter(log)
        return commit_count
    except subprocess.CalledProcessError:
        return {}

def get_problem_data():
    """Extract daily problem counts from commit messages"""
    try:
        log = subprocess.check_output([
            "git", "log", "--date=short", 
            "--pretty=format:%ad|%s"
        ], cwd=os.path.dirname(os.path.dirname(__file__))).decode().strip().split("\n")
        
        if log == ['']:
            return {}
        
        problem_count = defaultdict(int)
        
        problem_keywords = [
            'leetcode', 'lc:', 'algomaster', 'am:', 'problem', 'solution',
            'solved', 'completed', 'added', 'implement'
        ]
        
        for line in log:
            if '|' not in line:
                continue
                
            date, message = line.split('|', 1)
            message_lower = message.lower()
            
            if any(keyword in message_lower for keyword in problem_keywords):
                problem_count[date] += 1
        
        return dict(problem_count)
    except subprocess.CalledProcessError:
        return {}

def create_svg_chart(data, title, filename, color='#2E86AB'):
    """Create an SVG bar chart"""
    if not data:
        svg_content = f'''<svg width="600" height="300" xmlns="http://www.w3.org/2000/svg">
            <text x="300" y="150" text-anchor="middle" font-size="16" fill="#666">{title}</text>
            <text x="300" y="180" text-anchor="middle" font-size="14" fill="#999">No data available</text>
        </svg>'''
        with open(filename, 'w') as f:
            f.write(svg_content)
        return

    dates = sorted(data.keys())[-30:]  # Last 30 days
    counts = [data.get(date, 0) for date in dates]
    max_count = max(counts) if counts else 1
    
    width, height = 800, 400
    margin = 60
    chart_width = width - 2 * margin
    chart_height = height - 2 * margin
    
    svg_content = f'''<svg width="{width}" height="{height}" xmlns="http://www.w3.org/2000/svg">
        <style>
            .title {{ font-size: 18px; font-weight: bold; fill: #333; }}
            .axis {{ stroke: #ccc; stroke-width: 1; }}
            .bar {{ fill: {color}; opacity: 0.8; }}
            .label {{ font-size: 10px; fill: #666; }}
        </style>
        
        <text x="{width//2}" y="30" text-anchor="middle" class="title">{title}</text>
        
        <!-- Y-axis -->
        <line x1="{margin}" y1="{margin}" x2="{margin}" y2="{height-margin}" class="axis"/>
        
        <!-- X-axis -->
        <line x1="{margin}" y1="{height-margin}" x2="{width-margin}" y2="{height-margin}" class="axis"/>
    '''
    
    if counts:
        bar_width = chart_width / len(dates)
        for i, (date, count) in enumerate(zip(dates, counts)):
            bar_height = (count / max_count) * chart_height if max_count > 0 else 0
            x = margin + i * bar_width
            y = height - margin - bar_height
            
            svg_content += f'''
                <rect x="{x+2}" y="{y}" width="{bar_width-4}" height="{bar_height}" class="bar"/>
                <text x="{x + bar_width/2}" y="{height-margin+15}" text-anchor="middle" class="label">{date[-2:]}</text>
            '''
            
            if count > 0:
                svg_content += f'''<text x="{x + bar_width/2}" y="{y-5}" text-anchor="middle" class="label">{count}</text>'''
    
    total = sum(counts)
    avg = total / len(counts) if counts else 0
    svg_content += f'''
        <text x="10" y="{height-10}" class="label">Total: {total} | Avg: {avg:.1f}/day</text>
    </svg>'''
    
    with open(filename, 'w') as f:
        f.write(svg_content)

def main():
    """Generate both charts"""
    print("Generating daily commitment charts...")
    
    commits = get_commit_data()
    problems = get_problem_data()
    
    create_svg_chart(
        commits, 
        '📊 Daily Git Commits', 
        'assets/commits_per_day.svg',
        '#2E86AB'
    )
    
    create_svg_chart(
        problems, 
        '🎯 Daily Problems Solved', 
        'assets/problems_per_day.svg',
        '#A23B72'
    )
    
    print("Charts generated successfully!")
    print(f"Commits data: {len(commits)} days")
    print(f"Problems data: {len(problems)} days")

if __name__ == "__main__":
    main()