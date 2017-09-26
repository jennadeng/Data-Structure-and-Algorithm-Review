// Write your Checker class here
class Checker implements Comparator{

    public int compare(Object a, Object b){
        Player playerA = (Player) a;
        Player playerB = (Player) b;
        if (playerA.score == playerB.score){
            return playerA.name.compareTo(playerB.name);
        } else if(playerA.score < playerB.score){
            return 1;
        }else {
            return -1;
        }
    }

}
