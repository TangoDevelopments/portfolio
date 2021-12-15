using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;

public class GameOver : MonoBehaviour
{
    [SerializeField] GameObject gameOver;

    public void Restart() {
        PublicVars.reset();
        gameOver.SetActive(false);
        Time.timeScale = 1f;
        SceneManager.LoadScene(SceneManager.GetActiveScene().name);
    }

    public void Home() {
        Time.timeScale = 1f;
        PublicVars.reset();
        gameOver.SetActive(false);
        SceneManager.LoadScene("Startscene");
    }
}
