#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <cmath>
#include <iomanip>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// Побудова ідеально збалансованого дерева з відсортованого вектора
TreeNode* buildBalancedTree(const std::vector<int>& arr, int start, int end) {
    if (start > end) return nullptr;

    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(arr[mid]);

    root->left = buildBalancedTree(arr, start, mid - 1);
    root->right = buildBalancedTree(arr, mid + 1, end);

    return root;
}

// Заміна всіх від'ємних значень на їх модуль
void replaceNegativesWithAbs(TreeNode* root) {
    if (!root) return;
    if (root->val < 0) {
        root->val = std::abs(root->val);
    }
    replaceNegativesWithAbs(root->left);
    replaceNegativesWithAbs(root->right);
}

// Наочне графічне виведення структури дерева в консоль (горизонтальне)
void printTree(const TreeNode* root, int space = 0, int indent = 6) {
    if (!root) return;

    space += indent;
    printTree(root->right, space, indent);

    std::cout << std::string(space - indent, ' ') << "[" << root->val << "]\n";

    printTree(root->left, space, indent);
}

// Звільнення пам'яті
void freeTree(TreeNode* root) {
    if (!root) return;
    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

int main() {
    std::cout << "--- Завдання 2: Збалансоване бінарне дерево ---\n";
    int n;
    std::cout << "Введіть кількість вершин n: ";
    if (!(std::cin >> n) || n <= 0) return 0;

    // Генерація n випадкових чисел у діапазоні [-50; 50]
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> dist(-50, 50);

    std::vector<int> values(n);
    std::cout << "\nЗгенеровані випадкові числа:\n";
    for (int i = 0; i < n; ++i) {
        values[i] = dist(gen);
        std::cout << values[i] << " ";
    }
    std::cout << "\n";

    // Сортуємо для побудови збалансованого дерева
    std::sort(values.begin(), values.end());

    TreeNode* root = buildBalancedTree(values, 0, n - 1);

    std::cout << "\n================ ПОЧАТКОВЕ ДЕРЕВО ================\n";
    printTree(root);

    // Заміна від'ємних значень їх модулями
    replaceNegativesWithAbs(root);

    std::cout << "\n================ ЗМІНЕНЕ ДЕРЕВО (|x|) ================\n";
    printTree(root);

    freeTree(root);
    return 0;
}
