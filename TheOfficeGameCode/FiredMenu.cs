using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.SceneManagement;


public class FiredMenu : MonoBehaviour
{
    TransitionManager _transitionManager;
    // Start is called before the first frame update
    void Start()
    {
        _transitionManager = FindObjectOfType<TransitionManager>();
    }

    // Update is called once per frame
    void Update()
    {
        
    }


    public void Home(){
        PublicVars.lives = 3;
        PublicVars.AlarmBot = false;
        PublicVars.canAdvance = false;
        PublicVars.enemyRadius = 3;
        PublicVars.hammer = false;
        _transitionManager.LoadScene("Beginning");
    }

    public void Quit(){
        Application.Quit();
    }

    public void Restart(){
        PublicVars.lives = 3;
        PublicVars.AlarmBot = false;
        PublicVars.canAdvance = false;
        PublicVars.enemyRadius = 3;
        PublicVars.hammer = false;
        _transitionManager.LoadScene("Level1");
    }
}
