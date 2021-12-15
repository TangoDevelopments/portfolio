using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;
using UnityEngine.UI;

public class PauseMenu : MonoBehaviour
{

    public Image black;
    public Animator anim;

    [SerializeField] GameObject pauseMenu;
    
    public void Pause() {
        pauseMenu.SetActive(true);
        Time.timeScale = 0f;
    }

    public void Resume() {
        pauseMenu.SetActive(false);
        Time.timeScale = 1f;
    }

    public void Restart() {
        PublicVars.reset();
        pauseMenu.SetActive(false);
        Time.timeScale = 1f;
        StartCoroutine(FadeToGame());
    }

    public void Home() {
        Time.timeScale = 1f;
        PublicVars.reset();
        pauseMenu.SetActive(false);
        StartCoroutine(FadeToStart());
    }

    public void first_level()
    {

        StartCoroutine(FadeToGame());
    }

    public void first_scene()
    {

        StartCoroutine(FadeToStart());
    }

    public void instructions()
    {

        StartCoroutine(FadeToInstruc());
    }

    IEnumerator FadeToGame() {
        anim.SetBool("Fade", true);
        yield return new WaitUntil(()=>black.color.a==1);
        SceneManager.LoadScene("1");
    }

    IEnumerator FadeToInstruc() {
        anim.SetBool("Fade", true);
        yield return new WaitUntil(()=>black.color.a==1);
        SceneManager.LoadScene("instructions");
    }

    IEnumerator FadeToStart() {
        anim.SetBool("Fade", true);
        yield return new WaitUntil(()=>black.color.a==1);
        SceneManager.LoadScene("Startscene"); 
    }
}
