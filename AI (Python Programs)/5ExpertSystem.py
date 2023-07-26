kb={
    'air':['aeroplane','helicopter','jet'],
    'water':['boat','ship','submarine'],
    'land':['car','bike','bicycle'],
}
def inference(prefs):
    prob={}
    for cusine, ingrediant in kb.items():
        cnt=sum(pref in ingrediant for pref in prefs)
        prob[cusine]=cnt/len(ingrediant)
    maxprob=max(prob.values())
    cusines=[cusine for cusine, p in prob.items() if p==maxprob]
    return cusines
def ask_pref():
    preferences=set(pref for ingrediant in kb.values() for pref in ingrediant)
    prefs=[]
    for pref in preferences:
        ans=input(f"Do you like to travel through {pref}?(y/n)")
        if ans=="y" :
            prefs.append(pref)
    return prefs
user_pref=ask_pref()
recom_trans=inference(user_pref)
if recom_trans:
    print("\nYour recommend ways to transport are:", ", ".join(recom_trans))
else:
    print("\nNo mentioned transport means match your preference")