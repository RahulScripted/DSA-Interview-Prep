#!/usr/bin/env python3
import os
import time
from datetime import datetime
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

BASE_DIR = os.path.dirname(os.path.abspath(__file__))
LEETCODE_DIR = os.path.join(BASE_DIR, "Leetcode")
ALGOMASTER_DIR = os.path.join(BASE_DIR, "AlgoMaster")
README_PATH = os.path.join(BASE_DIR, "README.md")

class ReadmeUpdater(FileSystemEventHandler):
    def __init__(self):
        self.last_update = 0
        
    def on_any_event(self, event):
        if event.is_directory or not event.src_path.endswith(('.cpp', '.js', '.sql', '.py')):
            return
        if time.time() - self.last_update < 2:
            return
        self.last_update = time.time()
        print(f"Change detected: {event.src_path}")
        update_readme()

def count_files(directory):
    return sum(1 for root, _, files in os.walk(directory) 
               for f in files if f.endswith(('.cpp', '.js', '.sql', '.py')))

def update_readme():
    leetcode_count = count_files(LEETCODE_DIR)
    algomaster_count = count_files(ALGOMASTER_DIR)
    total = leetcode_count + algomaster_count
    
    with open(README_PATH, 'r') as f:
        content = f.read()
    
    lines = content.split('\n')
    for i, line in enumerate(lines):
        if '| **LeetCode** |' in line:
            lines[i] = f'| **LeetCode** | {leetcode_count} | 7/day | 🔥 Active |'
        elif '| **AlgoMaster** |' in line:
            lines[i] = f'| **AlgoMaster** | {algomaster_count} | 3/day | 🔥 Active |'
        elif '| **Total** |' in line:
            lines[i] = f'| **Total** | **{total}** | **10/day** | ✅ On Track |'
        elif line.startswith('**Last Updated**:'):
            lines[i] = f'**Last Updated**: {datetime.now().strftime("%d/%m/%Y")}'
    
    with open(README_PATH, 'w') as f:
        f.write('\n'.join(lines))
    
    print(f"✅ README updated: LeetCode={leetcode_count}, AlgoMaster={algomaster_count}, Total={total}")

if __name__ == "__main__":
    print("🚀 Starting README auto-updater...")
    update_readme()
    
    event_handler = ReadmeUpdater()
    observer = Observer()
    observer.schedule(event_handler, LEETCODE_DIR, recursive=True)
    observer.schedule(event_handler, ALGOMASTER_DIR, recursive=True)
    observer.start()
    
    print(f"👀 Watching:\n  - {LEETCODE_DIR}\n  - {ALGOMASTER_DIR}")
    print("Press Ctrl+C to stop")
    
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()
