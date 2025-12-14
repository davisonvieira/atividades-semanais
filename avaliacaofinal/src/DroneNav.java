import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.*;

// Classe principal
public class DroneNav {

    // Representação do Grafo: Map<IdDaCamara, ListaDeVizinhos>
    private Map<Integer, List<Integer>> adjCams;

    public DroneNav() {
        this.adjCams = new HashMap<>();
    }

    // Adiciona um túnel entre duas câmaras (Grafo não-direcionado)
    public void addTunnel(int v, int w) {
        adjCams.putIfAbsent(v, new ArrayList<>());
        adjCams.putIfAbsent(w, new ArrayList<>());
        adjCams.get(v).add(w);
        adjCams.get(w).add(v);  // Conexão bidirecional
    }

    public Map<Integer, List<Integer>> getAdjCams() {
        return adjCams;
    }

    // Carrega a mina a partir de um arquivo .txt
    public void loadMine(String filename) {
        try (BufferedReader br = new BufferedReader(new FileReader(filename))) {

            String line = br.readLine();
            int numCams = Integer.parseInt(line.trim()); // Lê número de câmaras

            while ((line = br.readLine()) != null) {
                String[] parts = line.split("\\s+"); // divide por espaços
                int v = Integer.parseInt(parts[0]);
                int w = Integer.parseInt(parts[1]);
                addTunnel(v, w);
            }

            System.out.println("Mapa da mina carregado com sucesso!");

        } catch (IOException e) {
            System.err.println("Erro ao ler o arquivo: " + e.getMessage());
        }
    }

    // ----------------------------
    // TAREFA 1: Implementar o DFS
    // ----------------------------
    public Set<Integer> dfs(int start) {
        Stack<Integer> stackNodes = new Stack<>();
        stackNodes.push(start);
        Set<Integer> visited = new LinkedHashSet<>();
        while (!stackNodes.isEmpty()) {
            int node = stackNodes.pop();
            if (!visited.contains(node)) {
                visited.add(node);
                List<Integer> neighbors = adjCams.get(node);
                for (int i = neighbors.size() - 1; i >= 0; i--) {
                    if (!visited.contains(neighbors.get(i))) {
                        stackNodes.push(neighbors.get(i));
                    }
                }
            }
        }
        return visited;
    }

    // Exemplo para testar
    public static void main(String[] args) {
        DroneNav dn = new DroneNav();
        dn.loadMine("C:/Users/davis/Documents/mina_basica.txt");




        Set<Integer> orderVisited = dn.dfs(0); // começa o DFS na câmara 0
        for (Integer v : orderVisited) {
            System.out.println(v);
        }
        if(dn.getAdjCams().size() > orderVisited.size()){
            System.out.println("Mapeamento incompleto. Áreas inacessíveis detectadas.");
        }

        System.out.println("________________________________");

        List<Integer> visitedBfs = dn.findShortestPathBFS(2, 0);
        for (Integer v : visitedBfs) {
            System.out.println(v);
        }
    }


    // TAREFA 2: Implementar o BFS (Resgate Rápido)
// Deve retornar ou imprimir o CAMINHO MAIS CURTO (ex: 8-2-5)
    public List<Integer> findShortestPathBFS(int startNode, int targetNode) {

        Queue<Integer> queueNodes = new LinkedList<>();
        Set <Integer> visited = new LinkedHashSet<>();
        Map <Integer, Integer> relation = new HashMap<>();

        queueNodes.add(startNode);
        visited.add(startNode);

        relation.put(startNode, null);

        while (!queueNodes.isEmpty()) {
            Integer currentNode = queueNodes.poll();

            if (currentNode == targetNode) {
                return getWay(relation, currentNode);
            }

            List <Integer> neighbors = adjCams.get(currentNode);

            for(Integer neighbor : neighbors){
                if(!visited.contains(neighbor)){
                    queueNodes.add(neighbor);
                    visited.add(neighbor);
                    relation.put(neighbor, currentNode);
                }
            }
        }

        return null;

    }

    private List<Integer> getWay(Map <Integer, Integer> relation, Integer current){
        List<Integer> way = new ArrayList<>();
        way.add(current);
        Integer next = relation.get(current);
        while (next != null) {
            way.add(next);
            next = relation.get(next);
        }

        Collections.reverse(way);

        return way;
    }


    // Método Main para testes
//    public static void main(String[] args) {
//
//        DroneNav drone = new DroneNav();
//
//        // Carrega a mina
//        drone.loadMine("mina.txt");
//
//        // Exemplo de DFS iniciando no nó 8
//        drone.startMappingDFS(8);
//
//        // Exemplo de BFS: procurar rota do 0 até 5
//        drone.findShortestPathBFS(0, 5);
//    }

}
