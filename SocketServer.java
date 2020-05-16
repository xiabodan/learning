import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.DataOutputStream;
import java.io.InputStreamReader;
import java.io.FileOutputStream;
import java.net.ServerSocket;
import java.net.Socket;

public class SocketServer {
    public static final int PORT = 12346;//监听的端口号 
    public static int Name= 0;//监听的端口号

    public static void main(String[] args) {
        System.out.println("服务器启动...\n");
        SocketServer server = new SocketServer();
        server.init();
    }

    public void init() {
        try {
            ServerSocket serverSocket = new ServerSocket(PORT);
            while (true) {
                // 一旦有堵塞, 则表示服务器与客户端获得了连接
                Socket client = serverSocket.accept();
                // 处理这次连接
                System.out.println("服务器接收开始");
                new HandlerThread(client);
            }
        } catch (Exception e) {
            System.out.println("服务器异常: " + e.getMessage());
        }
    }

    private class HandlerThread implements Runnable {
        private Socket socket;
        public HandlerThread(Socket client) {
            socket = client;
            new Thread(this).start();
        }

        public void run() {
            try {
                // 读取客户端数据
                DataInputStream input = new DataInputStream(socket.getInputStream());
                // String clientInputStr = input.readUTF();//这里要注意和客户端输出流的写方法对应,否则会抛 EOFException
                // 处理客户端数据
                // System.out.println("客户端发过来的内容:" + clientInputStr);

                // 向客户端回复信息
                DataOutputStream out = new DataOutputStream(new FileOutputStream("A" + Name));
                Name++;
                byte[] buf = new byte[1027 * 9];
                int len = 0;

                while ((len = input.read(buf)) != -1) {
                    out.write(buf, 0, len);
                }
                out.flush();
                // 发送键盘输入的一行
                // String s = new BufferedReader(new InputStreamReader(System.in)).readLine();
                // out.writeUTF(s);

                out.close();
                input.close();
                System.out.println("服务器接收完成");
            } catch (Exception e) {
                System.out.println("服务器 run 异常: " + e.getMessage());
            } finally {
                if (socket != null) {
                    try {
                        socket.close();
                    } catch (Exception e) {
                        socket = null;
                        System.out.println("服务端 finally 异常:" + e.getMessage());
                    }
                }
            } 
        }
    }
}
