# Auto README Updater

## Setup
```bash
pip install -r requirements.txt
```

## Usage

### Run the watcher:
```bash
python3 update_readme.py
```

The script will:
- Monitor `Leetcode/` and `AlgoMaster/` folders
- Auto-update README.md when you add/remove files
- Update counts and last updated date

### Run in background:
```bash
nohup python3 update_readme.py > updater.log 2>&1 &
```

### Stop background process:
```bash
pkill -f update_readme.py
```
