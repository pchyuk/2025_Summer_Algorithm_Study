from datetime import datetime, timedelta

now_utc = datetime.utcnow()

korea_time = now_utc + timedelta(hours = 9)

formatted_time = korea_time.strftime("%Y-%m-%d")

print(formatted_time)