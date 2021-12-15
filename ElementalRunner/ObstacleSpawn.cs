using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class ObstacleSpawn : MonoBehaviour
{
    public GameObject[] obstacles;
    public GameObject[] enemies;
    public float startSpawnTime = 1f;
    public float timePerSpawn = 3f;
    public float x = 0;
    public float y = 5;
    public float z = 0;
    public float enemyX = 0;
    public float enemyY = 5;
    public float enemyZ = 0;
    public int enemySpawnOdds = 3;
    void Start()
    {
        Invoke ("Spawn", startSpawnTime);
    }

    void Spawn() {
            int barrierWillSpawn = Random.Range(0, 5);
            int spawnVal = Random.Range(0,obstacles.Length);
            if (barrierWillSpawn == 0) {
                spawnVal = Random.Range(5, obstacles.Length);
            }
            else {
                spawnVal = Random.Range(0, 5);
                int willEnemySpawn = Random.Range(0,enemySpawnOdds);
                if (willEnemySpawn == 0) {
                    GameObject enemyToSpawn = enemies[Random.Range(0,enemies.Length)];
                    var newEnemy = GameObject.Instantiate(enemyToSpawn, new Vector3(enemyX, enemyY, enemyZ), Quaternion.identity);
                }
            }
            GameObject obstacleToSpawn = obstacles[spawnVal];
            var newObstacle = GameObject.Instantiate(obstacleToSpawn, new Vector3(x, y, z), Quaternion.identity);
            if (timePerSpawn >= 2f) {
                timePerSpawn -= 0.1f;
                PublicVars.worldSpeed += 0.25f;
            }
            Invoke("Spawn", timePerSpawn);
    }
}