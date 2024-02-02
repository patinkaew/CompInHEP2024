import re
from pathlib import Path

tot_lumi_re = re.compile("\n(?P<indent>.*?)(?P<totlumi>totrecorded)\((?P<unit>.*)\).*?\n(\+|-)+?\n(?P<value_line>.*?)\|\n")

if __name__ == "__main__":
    lumi_text = Path("../brilcalc.log").read_text()
    match = tot_lumi_re.search(lumi_text)
    if match:
        indent = len(match.group("indent"))
        tot_lumi =float((match.group("value_line")[indent:]).strip())
        unit = match.group("unit") 
        if unit == "fb":
            print(round(tot_lumi, 1), "/fb")
        elif unit == "/pb":
            print(round(tot_lumi/1000, 1), "/fb")
        else:
            print(round(tot_lumi, 1), unit)