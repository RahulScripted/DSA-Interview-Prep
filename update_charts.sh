#!/bin/bash

echo "🔄 Updating daily commitment charts..."

# Run the Python script
python3 scripts/generate_stats.py

# Check if charts were generated
if [ -f "assets/commits_per_day.svg" ] && [ -f "assets/problems_per_day.svg" ]; then
    echo "✅ Charts updated successfully!"
    echo "📊 Commit chart: assets/commits_per_day.svg"
    echo "🎯 Problems chart: assets/problems_per_day.svg"
else
    echo "❌ Error generating charts"
    exit 1
fi