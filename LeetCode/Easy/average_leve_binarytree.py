class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        level = 0
        queue = [(root,0)]
        from collections import defaultdict
        level_sum = defaultdict(int)
        level_count = defaultdict(int)
        while queue:
            node,level = queue.pop(0)
            level_sum[level] += node.val
            level_count[level] += 1
            if node.left:
                queue.append((node.left,level+1))
            if node.right:
                queue.append((node.right,level+1))
        
        result = []
        for key,val in level_sum.items():
            result.append(val/float(level_count[key]))
        
        return result