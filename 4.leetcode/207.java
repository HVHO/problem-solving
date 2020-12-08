// 207. Course Schedule
import java.util.ArrayList;
import java.util.List;
class Solution {
    ArrayList<Integer> visit;
    ArrayList<ArrayList<Integer>> map;
    Boolean dfs(int cur) {
        // 현재 탐색 중 방문한 노드 재방문 -> cycle
        if(visit.get(cur) == -1) {
            return false;
        // 이미 이전에 완전 탐색 완료한 노드 -> 탐색 필요 x
        } else if (visit.get(cur) == 1) {
            return true;
        // map 기준 다음 노드들을 dfs 로 방문 중 하나라도 false -> 전체 false return 후 terminate
        } else {
            visit.set(cur, -1);
            for(int next : map.get(cur))
            {
                if(!dfs(next)) return false;
            }
        }
        visit.set(cur, 1);
        return true;
    }
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        // 방향성 그래프 cycle 검증 문제
        // visit 배열 생성 0 - 초기상태 / 1 - 해당 노드기준 하위 노드들 탐색 완료 / -1 - dfs 탐색 중
        visit = new ArrayList<>();
        for(int i = 0; i < numCourses; i++)
            visit.add(0);
        // disjoint list 생성 -> node 개수 최대 10e5, disjoint map 불가 ( 4*10e10 byte )
        map = new ArrayList<>();
        for(int i = 0; i < numCourses; i++)
            map.add(new ArrayList<Integer>());
        for(int[] i : prerequisites) {
            map.get(i[1]).add(i[0]);
        }
        // dfs ㅌㅏㅁ색
        for(int i = 0; i < numCourses; i++) {
            // 아직 방문하지 않은 노드만 탐색
            if(visit.get(i) == 0) {
                if(!dfs(i)) return false;
            }
        }
        return true;
    }
}